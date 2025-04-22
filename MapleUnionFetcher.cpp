/*
#include <iostream>
#include <string>
#include <curl/curl.h>
#include <nlohmann/json.hpp>

// ���� �����͸� ������ ����
std::string response_data;

// libcurl�� �ݹ� �Լ�
size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    size_t totalSize = size * nmemb;
    response_data.append((char*)contents, totalSize);
    return totalSize;
}

int main() {
    CURL* curl;
    CURLcode res;

    // �ʱ�ȭ
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        // API Ű�� ĳ���� �̸� ����
        std::string api_key = "test_04ff0a6fda7bdae77df4708cc3831abfbb60275226a6872d3dc49aa93f2b1413efe8d04e6d233bd35cf2fabdeb93fb0d";
        std::string character_name = "ĳ�����̸�"; // ���⿡ ��ȸ�� ĳ���� �̸��� �Է�

        // ĳ���� ID ��ȸ�� ���� URL
        std::string url = "https://open.api.nexon.com/maplestory/v1/id?character_name=" + curl_easy_escape(curl, character_name.c_str(), character_name.length());

        // ��� ����
        struct curl_slist* headers = NULL;
        headers = curl_slist_append(headers, ("x-nxopen-api-key: " + api_key).c_str());

        // ��û ����
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);

        // ��û ����
        res = curl_easy_perform(curl);

        if (res != CURLE_OK) {
            std::cerr << "��û ����: " << curl_easy_strerror(res) << std::endl;
        }
        else {
            // ���� ������ �Ľ�
            auto json_response = nlohmann::json::parse(response_data);
            std::string ocid = json_response["ocid"];

            // ���Ͽ� ���� ��ȸ�� ���� URL
            std::string union_url = "https://open.api.nexon.com/maplestory/v1/union?ocid=" + ocid;

            // ���� ������ �ʱ�ȭ
            response_data.clear();

            // ��û ����
            curl_easy_setopt(curl, CURLOPT_URL, union_url.c_str());

            // ��û ����
            res = curl_easy_perform(curl);

            if (res != CURLE_OK) {
                std::cerr << "��û ����: " << curl_easy_strerror(res) << std::endl;
            }
            else {
                // ���� ������ �Ľ�
                auto union_response = nlohmann::json::parse(response_data);
                std::cout << "���Ͽ� ����: " << union_response.dump(4) << std::endl;
            }
        }

        // ����
        curl_slist_free_all(headers);
        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
    return 0;
}
*/