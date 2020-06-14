#include "grid.h"
#include "grid_given.cpp"

// PA1 functions


/**
 * Destroys the current Grid. This function should ensure that
 * memory does not leak on destruction of a grid.
 */
Grid::~Grid(){ /*your code here*/
clear();

}

/**
 * Rotate column c (column 0 is the first) by count positions.
 * If column c is ABCDE (top to bottom) in grid g then column c
 * in grid g should be DEABC after the call g.rotateC(c, 2).
 * Rotate headOfRow_ if necessary.
 */
 void Grid::rotateR(int r, int count) { /* your code here */
  for (int i = 0 ; i< count; i++){
    r = r % numRows();
    Node* start = headOfRow_[r];
    Node* up = start ->up;
    Node* down = start -> down;
    int col = 0;

    do {
      if (r==0){
        headOfCol_[col] = start ->left;
      }
      start -> up = up -> right;
      start -> down = down ->right;
      up-> down = start -> left;
      down -> up = start ->left;

      start = start ->right;
      up = up -> right;
      down = down -> right;

      col++;
    }
    while (start != headOfRow_[r]);
    headOfRow_[r] = start ->left;
 }
 }


 	// for (int i = 0; i < count; i++) {
 	// 	r = r % numRows();
 	// 	if (r == numRows()) {
 	// 		for (int j = 0; j < numCols(); j++) {
 	// 			headOfRow_[r]->down = headOfRow_[0]->right;
 	// 			headOfRow_[0]->right->up = headOfRow_[r];
 	// 			headOfRow_[r]->up = headOfRow_[r-1]->right;
 	// 			headOfRow_[r-1]->right->down = headOfRow_[r];
 	// 			headOfRow_[r] = headOfRow_[r]->left;
 	// 		}
 	// 	}
 	// 	if (r == 0) {
 	// 		for (int j = 0; j < numCols(); j++) {
 	// 			headOfRow_[r]->down = headOfRow_[1]->right;
 	// 			headOfRow_[1]->right->up = headOfRow_[r];
 	// 			headOfRow_[r]->up = headOfRow_[numRows()]->right;
 	// 			headOfRow_[numRows()]->right->down = headOfRow_[r];
 	// 			headOfRow_[r] = headOfRow_[r]->left;
 	// 		}
 	// 	}
 	// 	else {
 	// 		for (int j = 0; j < numCols(); j++) {
 	// 			headOfRow_[r]->down = headOfRow_[r+1]->right;
 	// 			headOfRow_[r+1]->right->up = headOfRow_[r];
 	// 			headOfRow_[r]->up = headOfRow_[r-1]->right;
 	// 			headOfRow_[r-1]->right->down = headOfRow_[r];
 	// 			headOfRow_[r] = headOfRow_[r]->left;
 	// 		}
 	// 	}
 	// }
 //}

 /**
  * Rotate column c (column 0 is the first) by count positions.
  * If column c is ABCDE (top to bottom) in grid g then column c
  * in grid g should be DEABC after the call g.rotateC(c, 2).
  * Rotate headOfRow_ if necessary.
  */
 void Grid::rotateC(int c, int count) { /* your code here */
 	// c = c % numCols();
 	// for(int i = 0; i < count; i++) {
 	// 	if (c == numCols()) {
 	// 		for (int j = 0; j < numRows(); j++) {
 	// 			headOfCol_[c]->right = headOfCol_[0]->down;
 	// 			headOfCol_[0]->down->left = headOfCol_[c];
 	// 			headOfCol_[c]->left = headOfCol_[c-1]->down;
 	// 			headOfCol_[c-1]->down->right = headOfCol_[c];
 	// 			headOfCol_[c] = headOfCol_[c]->up;
 	// 	}
 	// }
 	// 	if (c == 0) {
 	// 		for (int j = 0; j < numRows(); j++) {
 	// 			headOfCol_[c]->right = headOfCol_[c+1]->down;
 	// 			headOfCol_[c+1]->down->left = headOfCol_[c];
 	// 			headOfCol_[c]->left = headOfCol_[numCols()]->down;
 	// 			headOfCol_[numCols()]->down->right = headOfCol_[c];
 	// 			headOfCol_[c] = headOfCol_[c]->up;
 	// 	}
 	// }
 	// 	else {
 	// 		for (int j = 0; j < numRows(); j++) {
 	// 			headOfCol_[c]->right = headOfCol_[c+1]->down;
 	// 			headOfCol_[c+1]->down->left = headOfCol_[c];
 	// 			headOfCol_[c]->left = headOfCol_[c-1]->down;
 	// 			headOfCol_[c-1]->down->right = headOfCol_[c];
 	// 			headOfCol_[c] = headOfCol_[c]->up;
 	// 		}
 	// 	}
 	// }


  for (int i = 0 ; i< count; i++){
    Node* start = headOfCol_[c];
    Node* left = start ->left;
    Node* right = start -> right;
    int row = 0;

    do {
      if (c==0){
        headOfRow_[row] = start ->up;
      }
      start -> left = left -> down;
      start -> right = right ->down;
      left-> right = start -> up;
      right -> left = start ->up;

      start = start ->down;
      left = left -> down;
      right = right -> down;

      row++;
    }
    while (start != headOfCol_[c]);
    headOfCol_[c] = start ->up;
 }
}

/**
 * Destroys all dynamically allocated memory associated with the
 * current Grid class. Clears headOfRow_ and headOfCol_ vectors.
 * Sets bwidth_, bheight_ to zero.
 * After clear() the grid represents an empty grid.
 */
 void Grid::clear() { /*your code here*/
      for (unsigned i = 0; i < headOfRow_.size(); i++) {
          Node * head = headOfRow_[i];
          if (head == NULL) continue;
          Node * n = head->right;

          while (n != head) {
              n = n->right;
              delete n->left;
          }
          delete n;
          headOfRow_[i] = NULL;
      }

      bwidth_ = 0;
      bheight_ = 0;
  }



/**
 * Makes the current Grid a copy of the "other" Grid.
 * The dimensions should be the same.  The Nodes should
 * contain the same blocks, but the Nodes should be newly
 * allocated. This function is used in both the copy
 * constructor and the assignment operator for Grids.
 */
void Grid::copy(Grid const& other) { /*your code here*/
	clear();
	bwidth_ = other.headOfCol_.size();
  bheight_ = other.headOfRow_.size();
	Node* curr = other.headOfCol_[0];
	vector<vector<Node *>> A;
	for(int j=0; j<bwidth_; j++) {
		vector<Node *> temp;
		for(int i=0; i<bheight_; i++) {
			Node* p = new Node(curr->block);
			temp.push_back(p);
			curr = curr->down;
		}
		A.push_back(temp);
		curr = curr->right;
	}
	for( int j=0; j<bwidth_; j++ ) {
   		for( int i=0; i<bheight_; i++ ) {
      		Node *p = A[j][i];

      		p->up    = A[(j==0) ? bwidth_-1 : j-1] [i];
      		p->down  = A[(j==bwidth_-1) ? 0 : j+1][i];
      		p->left  = A[j] [(i==0) ? bheight_-1 : i-1];
      		p->right = A[j] [(i==bheight_-1) ? 0 : i+1];
    	}
  	}
  	for( int j=0; j<bwidth_; j++ ) {
    	headOfRow_.push_back(A[j][0]);
  	}
  	for( int i=0; i<bheight_; i++ ) {
    	headOfCol_.push_back(A[0][i]);
  	}
  	bheight_ = other.bheight_;
  	bwidth_ = other.bwidth_;
  }
