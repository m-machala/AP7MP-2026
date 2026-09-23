#include <iostream>

using namespace std;

class Receiver {
public:
    void receive() {
        cout << "received" << endl;
    }
};

class Sender {
private:
    Receiver* receiverInstance;

public:
    Sender(Receiver* r) {
        receiverInstance = r;
    }

    void send() {
        cout << "sent" << endl;

        receiverInstance->receive();
    }
};

int main()
{
    Receiver receiver;

    Sender sender(&receiver);

    sender.send();

    return 0;
}
