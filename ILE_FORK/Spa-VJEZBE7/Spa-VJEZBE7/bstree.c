#include <stdio.h>
#include <malloc.h>
#include "bstree.h"

BSTree NewBSTree()
{
	return NULL;
}

void AddNode(BSTree *bst, char *word)
{
	if (*bst == NULL) {
		(*bst) = (Node*)malloc(sizeof(Node));
		(*bst)->word = strdup(word);
		(*bst)->left = NULL;
		(*bst)->right = NULL;
	}
	else if (strcmp(word, (*bst)->word) == 0) {	
		return;
	}
	else if (strcmp(word, (*bst)->word) > 0) {
		AddNode(&(*bst)->right, word);
	}
	else if (strcmp(word, (*bst)->word) < 0) {	
		AddNode(&(*bst)->left, word);
	}

}

int BSTHeight(BSTree bst)
{
	if (bst == NULL)
		return 0;
	else {
		int ld = BSTHeight(bst->left);
		int dd = BSTHeight(bst->right);

		if (ld > dd)
			return ld + 1; 
		else
			return ld + 1;
	}
	return 0;
}

void PrintBSTree(BSTree bst)
{
	//In order setnja potrebno ovdi
	if (bst == NULL) {
		return;
	}
	PrintBSTree(bst->left);
	printf("%s\n", bst->word);
	PrintBSTree(bst->right);
}

void SaveBSTree(BSTree bst, FILE *fd)
{
	//Pre order setnja ovdi
	if (bst == NULL) {
		return;
	}
	fprintf(fd, "%s,", bst->word);	
	SaveBSTree(bst->left, fd);	
	SaveBSTree(bst->right, fd);
}

void DeleteBSTree(BSTree bst)
{
	//Post order
	if (bst == NULL) {
		return;
	}
	DeleteBSTree(bst->left);	
	DeleteBSTree(bst->right);	
	free(bst->word);
	free(bst);
}

BSTree LoadBSTree(FILE *fd)
{
	BSTree bst;
	bst = NewBSTree();
	char buffer[max_velicina];
	while (readWord(fd, buffer)) {
		AddNode(&bst, strdup(buffer));
	}
	return bst;
}
