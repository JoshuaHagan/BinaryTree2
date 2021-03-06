#include "BinaryTree.h"

void BinaryTree::draw(aie::Renderer2D* renderer,aie::Font* g_systemFont, TreeNode* selected)
{
	draw(renderer, m_pRoot, 640, 680, 640, g_systemFont ,selected);
	
}

void BinaryTree::draw(aie::Renderer2D* renderer, TreeNode* pNode, int x, int y, int horizontalSpacing, aie::Font* g_systemFont, TreeNode* selected)
{

	horizontalSpacing /= 2;

	if (pNode)
	{
		if (pNode->hasLeft())
		{
			renderer->setRenderColour(1, 0, 0);
			renderer->drawLine(x, y, x - horizontalSpacing, y - 80);
			draw(renderer, pNode->getLeft(), x - horizontalSpacing, y - 80, horizontalSpacing, g_systemFont, selected);
		}

		if (pNode->hasRight())
		{
			renderer->setRenderColour(1, 0, 0);
			renderer->drawLine(x, y, x + horizontalSpacing, y - 80);
			draw(renderer, pNode->getRight(), x + horizontalSpacing, y - 80, horizontalSpacing, g_systemFont, selected);
		}
		
		pNode->draw(renderer, x, y, g_systemFont, (selected == pNode));
	}
}

bool BinaryTree::isEmpty() const
{
	if (m_pRoot != nullptr)
	{
		m_pRoot == nullptr;
		
		return false;
	}
	return true;
}

void BinaryTree::insert(int a_nValue)
{
	TreeNode* current;
	TreeNode* parent;

	if (isEmpty())
	{
		m_pRoot = new TreeNode(a_nValue);
		m_pRoot == nullptr;
		return;
	}	
	else
	{
		current = m_pRoot;
		return;
	}
	
	while (current != nullptr)
	{
		if (current->getData() < a_nValue)
		{
			current->getLeft();
			current = current->getLeft();
		}
		else if (current->getData() > a_nValue)
		{
			current->getRight();
			current = current->getRight();
		}
		else if (current->getData() == a_nValue)
			return;
	}

	if (a_nValue < current->getData())
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

void BinaryTree::remove(int value)
{
	TreeNode* currentNode;
	TreeNode* ParentNode;

	while (ParentNode != nullptr)
	{
		if (currentNode->hasRight())
		{
			currentNode = ParentNode;
			currentNode = currentNode->getRight();
		}

		while (currentNode->hasLeft())
		{
			currentNode = ParentNode;
			currentNode = currentNode->getLeft();
		}
		
		if(ParentNode->getLeft())
		{
			currentNode->getLeft();
			currentNode = currentNode->getRight();
			delete currentNode;
		}

		if (ParentNode->getRight())
		{
			currentNode->getRight();
			currentNode = currentNode->getRight();
			delete currentNode;
		}
		
		if (currentNode != nullptr)
		{
			if (ParentNode->getLeft())
			{
				ParentNode->setLeft(currentNode);
			}
			else if (ParentNode->getRight())
			{
				currentNode->setRight(ParentNode);
			}
			else
			{
				delete m_pRoot;
			}
		}
	}
}

TreeNode * BinaryTree::find(int a_nValue)
{
	return nullptr;
}
