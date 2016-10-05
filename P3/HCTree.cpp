#include "HCTree.hpp"
#include <stack>

/*
 * Bo Hong Carson Chan A09354706
 * Lora Tam A09844493
 * cse 100 s2 2013
 * 8/21/13
 * 
 * HCTree.cpp
 */


// helper method for destructor
void freeHCNode(HCNode* node)
{
  if(node != 0)
  {
    freeHCNode(node->c0);
    freeHCNode(node->c1);
    delete node;
  }
  return; 
}

HCTree::~HCTree()
{
  freeHCNode(root);
}

void HCTree::build(const vector<int>& freqs)
{
  priority_queue<HCNode*, vector<HCNode*>, HCNodePtrComp> pq;

  // push all our nodes/frequency in a prority_queue
  for(int i = 0; i < freqs.size(); i++ )
  {
    if(freqs.at(i) != 0 )
    {
      leaves[i] = new HCNode(freqs.at(i),i);
      pq.push(leaves[i]); 
    }
  }
  
  if(pq.size() == 1 )
  {
    HCNode* node = new HCNode(0,0);
    pq.push(node);
  }
  
  // keep combining the smallest two nodes/trees into one tree
  while(pq.size() > 1 )
  {
    HCNode* smallest = pq.top();
	pq.pop();
    
    HCNode* smallest2 = pq.top();
	pq.pop();

    int combinedCount = smallest->count + smallest2->count;
    HCNode* newNode = new HCNode(combinedCount,0,smallest, smallest2);
    smallest->p = newNode;
    smallest2->p = newNode;

    pq.push(newNode);
  }
  // set the root afterall
  root = pq.top();
}

void HCTree::encode(byte symbol, BitOutputStream& output) const
{
  HCNode* cur = leaves[symbol];
  stack<int> code;
 
  //cout << (char)symbol << endl;
  //cout << symbol << endl;
 // cout << (int)symbol << endl;
  while(cur != root)
  {
    if(cur->p->c1 == cur )
    {
	//cout << "child 1" << endl;
      code.push(1);
    }
    if(cur->p->c0 == cur )
    {
	//cout << "child 0" << endl;
      code.push(0);
    }
   
    cur = cur->p;
  }

  while(!code.empty() )
  {
    output.writeBit(code.top());
    code.pop();
  }
}

int HCTree::decode(BitInputStream& input) const
{
  HCNode* curNode = root;
  int bit;
  
  // traverse down the hctree according to the code
  // until we reach a leaf, finding our symbol
  while(curNode->c0 != NULL && curNode->c1 != NULL)
  {
    bit = input.readBit();
    
    if(bit == 0)
      curNode = curNode->c0;
    
    if(bit == 1)
      curNode = curNode->c1;
  }

  return curNode->symbol;
}
