#include <stdio.h>
#include <malloc.h>
#include "bstree.h"

BSTree NewBSTree(){
	return NULL;
}
void CreateNode(BSTree *bst, char *word){
	*bst = (BSTree)malloc(sizeof(Node));
	(*bst)->left = NULL;
	(*bst)->right = NULL;
	(*bst)->word = word;
}

void AddNode(BSTree *bst, char *word){
	if(*bst == NULL) 
	return CreateNode(bst, word);
	
	else if(strcmp((*bst)->word, word) > 0)
	return AddNode(&(*bst)->left, word);
	
	else if(strcmp((*bst)->word, word) < 0)
	return AddNode(&(*bst)->right, word);
}

int BSTHeight(BSTree bst){
	if (bst==NULL)
	return 0;
	int left_depth=BSTHeight(bst->left);
	int right_depth=BSTHeight(bst->right);
	if (left_depth>right_depth)
	return left_depth+1;
	else
	return right_depth+1;
}

void PrintBSTree(BSTree bst){
	if (bst==NULL)
	return;
	PrintBSTree(bst->left);
	printf ("STRING:\t %s\n",bst->word);
	PrintBSTree(bst->right);
}

void SaveBSTree(BSTree bst, FILE *fd){
	if(bst == NULL) 
	return;
	fprintf(fd, "%s ", bst->word);
	SaveBSTree(bst->left, fd);
	SaveBSTree(bst->right, fd);
}

void DeleteBSTree(BSTree bst){
	if(bst == NULL) 
	return;
	DeleteBSTree(bst->left);
	DeleteBSTree(bst->right);
	printf("\n Brise se čvor: %s\n", bst->word);
	free(bst->word);
	free(bst);
}

BSTree LoadBSTree(FILE *fd){
	BSTree bst;
	bst = NewBSTree();
	char buffer[1024];
	while(readWord(fd, buffer)){
		printf("%s\n", buffer);
		AddNode(&bst, strdup(buffer));
	}
	return bst;
}
