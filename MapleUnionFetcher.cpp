/*
#include <iostream>
#include <string>
#include <curl/curl.h>
#include <nlohmann/json.hpp>

// 응답 데이터를 저장할 변수
std::string response_data;

// libcurl의 콜백 함수
size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    size_t totalSize = size * nmemb;
    response_data.append((char*)contents, totalSize);
    return totalSize;
}

int main() {
    CURL* curl;
    CURLcode res;

    // 초기화
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        // API 키와 캐릭터 이름 설정
        std::string api_key = "test_04ff0a6fda7bdae77df4708cc3831abfbb60275226a6872d3dc49aa93f2b1413efe8d04e6d233bd35cf2fabdeb93fb0d";
        std::string character_name = "캐릭터이름"; // 여기에 조회할 캐릭터 이름을 입력

        // 캐릭터 ID 조회를 위한 URL
        std::string url = "https://open.api.nexon.com/maplestory/v1/id?character_name=" + curl_easy_escape(curl, character_name.c_str(), character_name.length());

        // 헤더 설정
        struct curl_slist* headers = NULL;
        headers = curl_slist_append(headers, ("x-nxopen-api-key: " + api_key).c_str());

        // 요청 설정
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);

        // 요청 실행
        res = curl_easy_perform(curl);

        if (res != CURLE_OK) {
            std::cerr << "요청 실패: " << curl_easy_strerror(res) << std::endl;
        }
        else {
            // 응답 데이터 파싱
            auto json_response = nlohmann::json::parse(response_data);
            std::string ocid = json_response["ocid"];

            // 유니온 정보 조회를 위한 URL
            std::string union_url = "https://open.api.nexon.com/maplestory/v1/union?ocid=" + ocid;

            // 응답 데이터 초기화
            response_data.clear();

            // 요청 설정
            curl_easy_setopt(curl, CURLOPT_URL, union_url.c_str());

            // 요청 실행
            res = curl_easy_perform(curl);

            if (res != CURLE_OK) {
                std::cerr << "요청 실패: " << curl_easy_strerror(res) << std::endl;
            }
            else {
                // 응답 데이터 파싱
                auto union_response = nlohmann::json::parse(response_data);
                std::cout << "유니온 정보: " << union_response.dump(4) << std::endl;
            }
        }

        // 정리
        curl_slist_free_all(headers);
        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
    return 0;
}
*/