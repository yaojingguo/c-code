#include <stdio.h>

#define MAX_LEAF_COUNT 100
/*
 *        1
 *      /   \
 *     2     3
 *   /      /
 *  4      5
 */
struct node {
	int no;
	int level;
	struct node *left;
	struct node *right;
};

struct node *array[MAX_LEAF_COUNT];
int index = -1;

/* Find all the leaf nodes */
void findLeaves(struct node* node, int level) {
	if (node->left == NULL && node->right == NULL) {
		node->level = level;
		array[++index] = node;
	}
	level++;
	if (node->left != NULL)
		findLeaves(node->left, level);
	if (node->right != NULL)
		findLeaves(node->right, level);
}

int findDeepestRight(struct node *root) {
	index = -1;
	findLeaves(root, 1);

	int i;
	struct node* deepestRight = NULL;
	for (i = 0; i <= index; i++) 
		if (deepestRight == NULL || deepestRight->level <= array[i]->level)
			deepestRight = array[i];	
	return deepestRight->no;
}

int main(int argc, const char *argv[]) {
	int result;
	struct node n1, n2, n3, n4, n5;
	n1.no = 1; n2.no = 2; n3.no = 3; n4.no = 4; n5.no = 5;
	/*
	 *        1
	 *      /   \
	 *     2     3
	 *   /      /
	 *  4      5
	 */
	n1.left = &n2; n1.right = &n3;
	n2.left = &n4; n2.right = NULL;
	n4.left = NULL; n4.right = NULL;
	n3.left = &n5; n3.right = NULL;
	n5.left = NULL; n5.right = NULL;
	result = findDeepestRight(&n1);
	printf("tree1's deepest right: %d\n", result);

	/*
	 *       1
	 *     /
	 *    2
	 *  /
	 * 3
	 */
	n1.left = &n2; n1.right = NULL;
	n2.left = &n3; n2.right = NULL;
	n3.left = NULL; n3.right = NULL;
	result = findDeepestRight(&n1);
	printf("tree1's deepest right: %d\n", result);

	return 0;
}
