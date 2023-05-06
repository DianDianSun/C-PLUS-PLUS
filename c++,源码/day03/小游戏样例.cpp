#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Game {
public:
    Game(int max_num) : max_num_(max_num), secret_num_(rand() % max_num_ + 1), guess_count_(0) {}
    void play();
private:
    int max_num_;
    int secret_num_;
    int guess_count_;
    bool guess(int num);
};

void Game::play() {
    cout << "猜数字游戏开始！" << endl;
    while (true) {
        int num;
        cout << "请输入一个 1-" << max_num_ << " 之间的整数：" << endl;
        cin >> num;
        if (guess(num)) {
            cout << "恭喜你猜对了！" << endl;
            break;
        }
    }
    cout << "你一共猜了 " << guess_count_ << " 次。" << endl;
}

bool Game::guess(int num) {
    guess_count_++;
    if (num == secret_num_) {
        return true;
    } else if (num < secret_num_) {
        cout << "猜小了！" << endl;
        return false;
    } else {
        cout << "猜大了！" << endl;
        return false;
    }
}

int main() {
    srand(time(NULL));
    Game game(100);
    game.play();
    return 0;
}
