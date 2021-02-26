/**
 * 標準入力からコマンドを待ち受ける
 *
 */

#include <boost/asio.hpp>
#include <boost/asio/io_context.hpp>
#include <boost/lexical_cast.hpp>
#include <iostream>
#include <vector>

struct app
{
    app() : console_input_(ioc_, 0) {}
    void start() {
        boost::asio::async_read_until(
            console_input_, sbuf_, '\n',
            [this](boost::system::error_code const& ec, std::size_t len) {
                std::istream is(&sbuf_);
                std::string line;

                std::getline(is, line);

                std::stringstream ss(line);
                std::string cmd;
                ss >> cmd;
                std::cout << cmd << std::endl;
            });

        ioc_.run();
    }

private:
    boost::asio::io_context ioc_;
    boost::asio::streambuf sbuf_;
    boost::asio::posix::stream_descriptor console_input_;
};

int main(int argc, char** argv) {
    app exe;
    exe.start();
    return 0;
}
