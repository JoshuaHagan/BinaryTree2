#pragma once
#include "Application.h"
#include "BinaryTree.h"
#include "TreeNode.h"

class CDDS_BinaryTreesApp: public aie::Application
{
public:
	BinaryTree  m_binaryTree;
	TreeNode* m_selectedNode;
	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();
protected:
	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;
};
