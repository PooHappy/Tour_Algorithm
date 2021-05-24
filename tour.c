#include <stdio.h>

typedef struct TreeNode {
	int data;
	struct TreeNode *left, *right;
}TreeNode;

void inorder(TreeNode* root) {	//��ȯ ���� ��ȸ Ž��
	if (root) {	//��Ʈ�� NULL�� �ƴϸ�
		inorder(root->left);	//root->left�� root�� �Ǿ� �ٽ� ����
		printf("%d ", root->data);	//root�� data�� ���
		inorder(root->right);	//root->right�� root�� �Ǿ� �ٽ� ����
	}
}
TreeNode* new_node(int data) {	//Insert���� root�� NULL�̸� ���ο� ��� ����
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));	//TreeNodeũ�⸸ŭ �Ҵ�
	temp->data = data;			//data�� �Ҵ�
	temp->left = temp->right = NULL;	//left, right�� NULL�� �ʱ�ȭ
	return temp;				//temp�� ��ȯ
}
TreeNode* Insert(TreeNode* root, int data) {
	if (root == NULL) 
		return new_node(data);	//root�� ���������
	if (data < root->data)		//data�� root->data���� ������
		root->left = Insert(root->left, data);	//left�� �̵� �� �翬��
	else if (data > root->data)	//data�� root->data���� ũ��
		root->right = Insert(root->right, data);	//right�� �̵� �� �翬��
	return root;
}
TreeNode* min_value_node(TreeNode* node) {	//
	TreeNode* current = node;
	while (current->left != NULL) {
		current = current->left;
	}
	return current;
}
TreeNode* Delete(TreeNode* root, int data) {	//data�� �ش��ϴ� node����
	if (root == NULL) {
		return root;
	}
	if (data < root->data) {	//data�� root->data���� ������
		root->left = Delete(root->left, data); //left�� �̵� �� �翬��
	}
	else if (data > root->data) {	//data�� root->data���� ũ��
		root->right = Delete(root->right, data);	//right�� �̵� �� �翬��
	}
	else {	// data���� �ش��ϴ� node�� ã����
			// �����ϴ� ��尡 left, right�� �����̶� NULL�̶��
		if (root->left == NULL) {	//root�� right���� temp�� �̾��ְ� root ����
			TreeNode* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) { //root�� left ���� temp�� �̾��ְ� root ����
			TreeNode* temp = root->left;
			free(root);
			return temp;
		}
			//�����Ϸ��� ��尡 left, right ��� �����ִ� ���
		TreeNode* temp = min_value_node(root->right); //�����ϴ� ���� ���� ����� ��, right����� ���� left��.
		root->data = temp->data;	
		root->right = Delete(root->right, temp->data);
	}
	return root;
}

int main() {
	TreeNode* TN[14] = { '\0', };		//TreeNode�� �־��� �迭 �������� TN ����.
	for (int i = 0; i < 14; i++) {
		TreeNode* n = (TreeNode*)malloc(sizeof(TreeNode));	//�ʱ�ȭ �ϸ� �迭�� �־���
		TN[i] = n;
	}
	TN[0]->left = TN[1];
	TN[0]->right = TN[2];
	TN[0]->data = 15;
	TN[1]->left = TN[3];
	TN[1]->right = TN[4];
	TN[1]->data = 10;
	TN[2]->left = NULL;
	TN[2]->right = TN[5];
	TN[2]->data = 16;
	TN[3]->left = NULL;
	TN[3]->right = TN[6];
	TN[3]->data = 4;
	TN[4]->left = NULL;
	TN[4]->right = NULL;
	TN[4]->data = 12;
	TN[5]->left = TN[7];
	TN[5]->right = TN[8];
	TN[5]->data = 20;
	TN[6]->left = TN[9];
	TN[6]->right = TN[10];
	TN[6]->data = 7;
	TN[7]->left = NULL;
	TN[7]->right = TN[11];
	TN[7]->data = 17;
	TN[8]->left = TN[12];
	TN[8]->right = TN[13];
	TN[8]->data = 25;
	TN[9]->left = NULL;
	TN[9]->right = NULL;
	TN[9]->data = 6;
	TN[10]->left = NULL;
	TN[10]->right = NULL;
	TN[10]->data = 8;
	TN[11]->left = NULL;
	TN[11]->right = NULL;
	TN[11]->data = 18;
	TN[12]->left = NULL;
	TN[12]->right = NULL;
	TN[12]->data = 21;
	TN[13]->left = NULL;
	TN[13]->right = NULL;
	TN[13]->data = 27;
	// Ʈ�� �� �ʱ�ȭ 
	printf("<<���� ��ȸ ���>>\n");
	inorder(TN[0]);
	//���� ��ȸ ���

	Delete(TN[0], 4);
	//data�� 4�� node ����
	Insert(TN[0], 13);
	//data�� 13�� ��� ����

	printf("\n\n<<4�� 13���� �ٲ� �� ���� ��ȸ ���>>\n");

	inorder(TN[0]);

	printf("\n\n<<20�� 5�� �ٲ� �� ���� ��ȸ ���>>\n");

	Delete(TN[0], 20);
	//data�� 20�� node ����
	Insert(TN[0], 5);
	//data�� 5�� ��� ����
	inorder(TN[0]);
	printf("\n");
}