#include "BinaryTree.h"

void BinaryTree::draw(aie::Renderer2D* renderer, TreeNode* selected)
{
	draw(renderer, m_pRoot, 640, 680, 640, selected);
}

void BinaryTree::draw(aie::Renderer2D* renderer, TreeNode* pNode, int x, int y, int horizontalSpacing, TreeNode* selected)
{
	horizontalSpacing /= 2;

	if (pNode)
	{
		if (pNode->hasLeft())
		{
			renderer->setRenderColour(1, 0, 0);
			renderer->drawLine(x, y, x - horizontalSpacing, y - 80);
			draw(renderer, pNode->getLeft(), x - horizontalSpacing, y - 80, horizontalSpacing, selected);
		}

		if (pNode->hasRight())
		{
			renderer->setRenderColour(1, 0, 0);
			renderer->drawLine(x, y, x + horizontalSpacing, y - 80);
			draw(renderer, pNode->getRight(), x + horizontalSpacing, y - 80, horizontalSpacing, selected);
		}
		
		pNode->draw(renderer, x, y, (selected == pNode));
	}
}

void BinaryTree::insert(int a_nValue)
{
	TreeNode* current;
	TreeNode* parent;

	if (isEmpty())
	{
		m_pRoot = new TreeNode(a_nValue);
	}	
	else
	{
		current = m_pRoot;
	}
	
	while (current != nullptr)
	{
		if (current->getData() < a_nValue)
		{
			current->getLeft();
			current = m_pRoot->getLeft();
		}
		else if (current->getData() > a_nValue)
		{
			current->getRight();
			current = m_pRoot->getRight();
		}
		else if (current->getData() == a_nValue)
			return;
	}

	if (a_nValue < parent->getData())
	{
		parent->getLeft();
		current = parent->getLeft();
	}
	else if (a_nValue > parent->getData())
	{
		parent->getRight();
		current = parent->getRight();
	}
}  

bool BinaryTree::findNode(int a_nSearchValue, TreeNode** ppOutNode, TreeNode** ppOutParent)
{
	TreeNode* current = m_pRoot;

	current = m_pRoot;
	while (current != nullptr)
	{
		if (a_nSearchValue == current->getData())
		{
			return true;
		}
		else if(a_nSearchValue < current->getData())
		{
			current->getLeft();
			current = m_pRoot->getLeft();
		}
		else
		{
			current->getRight();
			current = m_pRoot->getRight();
		}
	}
	return false;
}

//void BinaryTree::remove(int value)
//{
//	TreeNode* ppOutNode;
//	TreeNode* ppOutParent;
//
//	while (ppOutParent != nullptr)
//	{
//		ppOutNode->getLeft;
//		
//	}
//}++