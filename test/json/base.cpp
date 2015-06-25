#include <guiddef.h>
#include <string>

GUID cb_s2id(const std::string& _str){
    static GUID id;
    sscanf_s(_str.c_str(), "{%08X-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X}",
        &id.Data1, &id.Data2, &id.Data3,
        &id.Data4[0], &id.Data4[1],
        &id.Data4[2], &id.Data4[3],
        &id.Data4[4], &id.Data4[5],
        &id.Data4[6], &id.Data4[7]);
    return id;
}

std::string cb_id2s(const GUID& _id){
    char buf[64];
    _snprintf_s(
        buf,
        sizeof(buf),
        "{%08X-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X}",
        _id.Data1, _id.Data2, _id.Data3,
        _id.Data4[0], _id.Data4[1],
        _id.Data4[2], _id.Data4[3],
        _id.Data4[4], _id.Data4[5],
        _id.Data4[6], _id.Data4[7]);
    return std::string(buf);
}

int getcount(){
	return 5;
}

std::string getname(int id) {
	std::string namelist[] = {
		"alem",
		"bob",
		"candy",
		"diva",
		"flem",
	};
	return namelist[id];
}

GUID getGUID(int id) {
	std::string idlist[] = {
		"{A8E95E12-5065-42A9-B1B5-D3ED97B20CE0}",
		"{693A17C2-0DD4-49E6-9D50-239B721F34A4}",
		"{4B673484-6CEC-46B2-AD72-AF8E63E1613C}",
		"{9531D293-13D0-4FB9-B92E-1EDA482ABAF3}",
		"{adb72193-13D0-4FB9-B92E-1EDAeeeeeeee}",
	};

	return cb_s2id(idlist[id]);
}