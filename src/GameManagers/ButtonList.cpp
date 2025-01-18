/*
MIT License

Copyright (c) 2024 Quangnam1423

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include "ButtonList.h"
#include "Button.h"

QT::ButtonList::ButtonList()
{
	m_head = nullptr;
	m_root = nullptr;
	m_size = 0;
}

QT::ButtonList::~ButtonList()
{
	while (m_size != 0)
	{
		deleteButton();
	}
	m_head = nullptr;
	m_root = nullptr;
}

void QT::ButtonList::insertHead(Button& button)
{
	Node* newNode = new Node();
	newNode->button = &button;
	if (m_size == 0)
	{
		m_head = newNode;
		m_root = newNode;
	}
	else
	{
		newNode->nextNode = m_head;
		newNode->preNode = nullptr;
		m_head = newNode;
	}
	m_size += 1;
	return;
}

void QT::ButtonList::insertAfter(Button& button)
{
	Node* newNode = new Node();
	newNode->button = &button;
	if (m_size == 0)
	{
		m_head = newNode;
		m_root = newNode;
	}
	else
	{
		newNode->preNode = m_root;
		newNode->nextNode = nullptr;
		m_root = newNode;
	}
	m_size += 1;
	return;
}

void QT::ButtonList::insert(Button& button,unsigned int position)
{
	if (m_size < position)
		insertAfter(button);
	else
	{
		Node* newNode = new Node();
		newNode->button = &button;
		Node* iteratorNode = m_head;
		for (int i = 0; i < position; i++)
		{
			iteratorNode = iteratorNode->nextNode;
		}
		newNode->preNode = iteratorNode->preNode;
		newNode->nextNode = iteratorNode;
		newNode->preNode->nextNode = newNode;
		iteratorNode->preNode = newNode;
		m_size -= 1;
	}
	return;
}

void QT::ButtonList::deleteButton()
{
	Node* deleteNode = m_root;
	m_root = m_root->preNode;
	m_root->nextNode = nullptr;
	delete deleteNode->button;
	deleteNode->nextNode = nullptr;
	deleteNode->preNode = nullptr;
	m_size -= 1;
	return;
}

QT::Node* QT::ButtonList::begin()
{
	return m_head;
}

QT::Node* QT::ButtonList::rbegin()
{
	return m_root;
}


