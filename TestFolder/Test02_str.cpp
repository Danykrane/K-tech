//
// Created by Артём Гудзенко on 23.01.2023.
//


/*

std::string const page =
        "<html>"
        "<head>"
        "<title>Some title</title>"
        "</head>"
        "<body>"
        "<name>Алексеев Иван Петрович</name>"
        "<date>1976-01-01</date>"
        "<hours-worked>25</hours-worked>"
        "<name>Алексеев Иван Петрович</name>"
        "<car-true>YES</car-true>"
        "<tag>Some content</tag>"
        "</body>"
        "</html>";
cout <<page[0]<<endl;

std::string const tag = "tag";
vector<string> checks = {"name", "date" , "tag", "hours-worked", "car-true"};
std::string text;

for (auto it: checks){
string const opening = "<" + it + ">";
string const closing = "</" + it + ">";

string::size_type begin = page.find(opening);
if (begin != string::npos) {
begin += opening.length();
string::size_type end = page.find(closing, begin);
if (end != string::npos) {
text = page.substr(begin, end - begin);
}
}

cout << text << endl;
}
*/
//        string const opening = "<" + tag + ">";
//        string const closing = "</" + tag + ">";
//        string::size_type begin = page.find(opening);
//        if (begin != std::string::npos) {
//            begin += opening.length();
//            std::string::size_type end = page.find(closing, begin);
//            if (end != std::string::npos) {
//                text = page.substr(begin, end - begin);
//            }
//        }
//
//        cout << text << std::endl;
}
