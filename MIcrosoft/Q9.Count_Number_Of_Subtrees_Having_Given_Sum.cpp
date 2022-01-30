//User function Template for C++

int utiltityForCount(Node *root, int x, int &count)
{
	if (root == NULL)
		return 0;

	int ls = utiltityForCount(root->left, x, count);

	int rs = utiltityForCount(root->right, x, count);

	int sum = ls + rs + root->data;

	if (sum == x)
		count++;

	return sum;
}

int countSubtreesWithSumX(Node *root, int x)
{
	if (root == NULL)
		return 0;

	int count = 0;
	int bt = utiltityForCount(root, x, count);

	return count;
}