#include <stdio.h>

typedef struct TreeNode {
	int data;
	struct TreeNode *left, *right;
}TreeNode;

void inorder(TreeNode* root) {	//순환 중위 순회 탐색
	if (root) {	//루트가 NULL이 아니면
		inorder(root->left);	//root->left가 root가 되어 다시 실행
		printf("%d ", root->data);	//root의 data값 출력
		inorder(root->right);	//root->right가 root가 되어 다시 실행
	}
}
TreeNode* new_node(int data) {	//Insert에서 root가 NULL이면 새로운 노드 생성
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));	//TreeNode크기만큼 할당
	temp->data = data;			//data값 할당
	temp->left = temp->right = NULL;	//left, right값 NULL로 초기화
	return temp;				//temp값 반환
}
TreeNode* Insert(TreeNode* root, int data) {
	if (root == NULL) 
		return new_node(data);	//root가 비어있으면
	if (data < root->data)		//data가 root->data보다 작으면
		root->left = Insert(root->left, data);	//left로 이동 후 재연산
	else if (data > root->data)	//data가 root->data보다 크면
		root->right = Insert(root->right, data);	//right로 이동 후 재연산
	return root;
}
TreeNode* min_value_node(TreeNode* node) {	//
	TreeNode* current = node;
	while (current->left != NULL) {
		current = current->left;
	}
	return current;
}
TreeNode* Delete(TreeNode* root, int data) {	//data값 해당하는 node삭제
	if (root == NULL) {
		return root;
	}
	if (data < root->data) {	//data가 root->data보다 작으면
		root->left = Delete(root->left, data); //left로 이동 후 재연산
	}
	else if (data > root->data) {	//data가 root->data보다 크면
		root->right = Delete(root->right, data);	//right로 이동 후 재연산
	}
	else {	// data값에 해당하는 node를 찾으면
			// 삭제하는 노드가 left, right중 한쪽이라도 NULL이라면
		if (root->left == NULL) {	//root의 right값을 temp로 이어주고 root 삭제
			TreeNode* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) { //root의 left 값을 temp로 이어주고 root 삭제
			TreeNode* temp = root->left;
			free(root);
			return temp;
		}
			//삭제하려는 노드가 left, right 모두 갖고있는 경우
		TreeNode* temp = min_value_node(root->right); //삭제하는 노드와 가장 가까운 값, right노드의 가장 left값.
		root->data = temp->data;	
		root->right = Delete(root->right, temp->data);
	}
	return root;
}

int main() {
	TreeNode* TN[14] = { '\0', };		//TreeNode를 넣어줄 배열 포인터형 TN 생성.
	for (int i = 0; i < 14; i++) {
		TreeNode* n = (TreeNode*)malloc(sizeof(TreeNode));	//초기화 하며 배열에 넣어줌
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
	// 트리 값 초기화 
	printf("<<중위 순회 결과>>\n");
	inorder(TN[0]);
	//중위 순회 출력

	Delete(TN[0], 4);
	//data가 4인 node 삭제
	Insert(TN[0], 13);
	//data가 13인 노드 삽입

	printf("\n\n<<4가 13으로 바뀐 후 중위 순회 결과>>\n");

	inorder(TN[0]);

	printf("\n\n<<20이 5로 바뀐 후 중위 순회 결과>>\n");

	Delete(TN[0], 20);
	//data가 20인 node 삭제
	Insert(TN[0], 5);
	//data가 5인 노드 삽입
	inorder(TN[0]);
	printf("\n");
}