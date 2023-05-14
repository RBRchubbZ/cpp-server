#include "crow.h"
//#include "crow_all.h"
#include <string>


std::string displayImage(std::string imageCode);
std::string convertToBase64(std::string imageCode);

int main(){
    crow::SimpleApp app; //define your crow application

    //basic endpoint
    CROW_ROUTE(app, "/")([](){
        return "Hello world";
    });

    //json return
    CROW_ROUTE(app, "/getjson")([](){
        return "{\"name\": \"jeff\"}"; //"{\"name\": \"jeff\"}"
    });

    //json return // const request captures request from client
    CROW_ROUTE(app, "/postjson").methods("POST"_method) ([](const crow::request& r){
        // apply givin input into json --readvalue
        crow::json::rvalue req_body = crow::json::load(r.body); // value cant be returned as not yet
        // apply that value to a new variable --wvalue
        crow::json::wvalue seri_data = req_body; // 
        // get image base64 code
        std::string b64Code = convertToBase64(seri_data["ASM-IMG"].dump());

        //displayImage(b64Code); // display image in browser for test
        
        return b64Code;

    });

    app.port(8000).multithreaded().run();

}

//SEPERATED FOR VISUAL ONLY
std::string convertToBase64(std::string imageCode){
    std::string b64String = crow::utility::base64encode(imageCode, imageCode.size());
    return b64String;
}

//                        display to webpage JUST FOR DEBUGGING
//                        ERROR ON RENDER IMGTOSEND CHECK IF WORTH FIXING OR NAH 

// std::string displayImage(std::string imageCode){
//     auto page = crow::mustache::load("displayimage.html"); // load the given .html page from the templates directory 
//     crow::mustache::context imgToSend ({{"displayImage", imageCode}});// add the given "img" data to the specified component // from createImageString
//     return page.render(imgToSend); // send full page with rendered data on it
// }

// Note that the data must have "image:base64:" appended before the BASE64 data string.

//================================================================================================================
//                                                    HELL                                                       =
//================================================================================================================


// DELETE
// sends as string 
// CONVERT BASE64 IMAGE INTO DISPLAYABLE HTML TAG
// std::string createImageString(std::string imageCode){
//     std::string sliceStart = "<img src='data:image/jpeg;base64,";
//     std::string sliceEnd =  "'/>";
//     std::string imgToSend = sliceStart + imageCode + sliceEnd;
        
//     return imgToSend;
// }

// for proxy in harry.conf
// server {
//         listen 80;
//         server_name 192.168.0.75;

//         location / {
//                 proxy_pass http://localhost:8000/;
//         }
// }
//================================================================================================================
