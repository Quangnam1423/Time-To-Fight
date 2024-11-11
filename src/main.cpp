#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    // Tạo cửa sổ
    sf::RenderWindow window(sf::VideoMode(800, 600), "2D Animation");

    // Tải sprite sheet (giả sử là hình ảnh 4x4 với mỗi frame có kích thước 64x64)
    sf::Texture texture;
    if (!texture.loadFromFile("resource/Samurai/Attack_1.png")) {
        return -1;  // Không thể tải hình ảnh
    }

    // Tạo sprite
    sf::Sprite sprite(texture);
    sprite.setPosition(100 , 100);
    

    // Thiết lập frame hiện tại (ví dụ: nhân vật có 4 frame cho mỗi hành động)
    int frameWidth = 128;  // Độ rộng mỗi frame
    int frameHeight = 128; // Chiều cao mỗi frame
    int currentFrame = 0; // Khởi tạo frame ban đầu

    sprite.setTextureRect(sf::IntRect(0 , 0, frameWidth, frameHeight));

    // Thời gian để thay đổi frame (fps)
    sf::Clock clock;
    float frameTime = 0.2f;  // Thay đổi frame sau mỗi 0.2 giây
    clock.restart();

    while (window.isOpen())
    {
        sf::Time deltaTime = clock.getElapsedTime();

        // Xử lý sự kiện đóng cửa sổ
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Cập nhật frame
        if (deltaTime.asSeconds() > frameTime) {
            currentFrame++;
            if (currentFrame >= 6) currentFrame = 0;  // Nếu đã đi hết các frame thì quay lại

            // Cập nhật texture rectangle để lấy đúng frame
            sprite.setTextureRect(sf::IntRect(currentFrame * frameWidth, 0, frameWidth, frameHeight));
            //std::cout << "print" << std::endl;
            clock.restart();
        }

        // Vẽ sprite
        window.clear();
        window.draw(sprite);
        window.display();
    }

    return 0;
}
