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

#ifndef CLIENTCONNECT_H
#define CLIENTCONNECT_H

#include <SFML/Network.hpp>
#include <SFML/Network/IpAddress.hpp>
#include <SFML/System.hpp>

#include <thread>
#include <iostream>
#include <string>
#include <windows.data.json.h>
#include <thread>

#include "../../Singleton.h"

void sendData(ClientConnect& connect);
void receiveData(ClientConnect& connect);

class ClientConnect : public Singleton<ClientConnect>
{
friend class Singleton<ClientConnect>;
friend void senDate(ClientConnect& connect);
public:
	ClientConnect(std::string serverHost, int port);
	~ClientConnect();
	void init();
	void startConnect();
private:
	sf::TcpSocket* m_socket;
	sf::Socket::Status m_status;
	sf::Int32 m_serverPort;
	sf::IpAddress m_serverAddress;

	//sf::Thread m_thread;
};

#endif