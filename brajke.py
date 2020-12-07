# cetvrti
def zbroj(a, b):
    if b == a:
        return a
    return b + zbroj(a, b-1)
print(zbroj(1, 10))
