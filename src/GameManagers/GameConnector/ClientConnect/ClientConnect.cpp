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

#include "ClientConnect.h"

ClientConnect::ClientConnect(std::string serverHost, int port)
{
	m_serverAddress = sf::IpAddress(serverHost);
	m_serverPort = port;
	m_status = sf::Socket::Disconnected;
}

ClientConnect::~ClientConnect()
{
	if (m_socket != nullptr)
		delete m_socket;
	return;
}

void ClientConnect::startConnect()
{
	if (m_socket->connect(m_serverAddress, m_serverPort) != sf::Socket::Done)
	{
		m_status = sf::Socket::Done;
	}
	else 
		m_status = sf::Socket::Disconnected;
	return;
}

sf::TcpSocket *ClientConnect::getSocket()
{
    return m_socket;
}

void ClientConnect::setStatus(sf::Socket::Status status)
{
	m_status = status;
	return;
}

sf::Socket::Status ClientConnect::getStatus()
{
    return m_status;
}

void sendData(ClientConnect &connect)
{
	json data = {
		{"type", "message"},
		{"content", "Hello, message"},
		{"timestamp", "22:00:00"}
	};
	std::string jsonString = data.dump();
	if (connect.getSocket()->send(jsonString.c_str(), jsonString.size()) == sf::Socket::Done)
	{
		connect.setStatus(sf::Socket::Done);
	}
	else 
	{
		connect.setStatus(sf::Socket::Error);
	}
	return;
}

json receiveData(ClientConnect &connect)
{
	char buffer[1024];
	std::size_t received;
	if (connect.getSocket()->receive(buffer , sizeof(buffer), received) == sf::Socket::Done)
	{
		std::string jsonString (buffer, received);
		connect.setStatus(sf::Socket::Done);
		return json::parse(jsonString);
	}
	else 
	{
		connect.setStatus(sf::Socket::Error);
		return json();
	}
	return json();
}

json jsonEncoding(std::string str)
{
	return json::parse(str);
}

std::string jsonDecoding(json json)
{
	return json.dump();
}
