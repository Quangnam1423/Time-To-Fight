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
#ifndef BUTTONLIST_H
#define BUTTONLIST_H

class Button;
namespace QT
{
	struct Node
	{
		Button* button;
		struct Node* nextNode;
		struct Node* preNode;
		int position;
	};
	struct Iterator {

	};

	class ButtonList
	{
	public:
		ButtonList();
		~ButtonList();
		void insertHead(Button& button);
		void insertAfter(Button& button);
		void insert(Button& button,unsigned int position);
		void deleteButton();
		Node* begin();
		Node* rbegin();
	private:
		Node* m_head;
		Node* m_root;
		int m_size;
	};
}

#endif