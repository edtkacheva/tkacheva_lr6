#include "pch.h"
#include "tkacheva_group.h"

using namespace std;
BOOST_CLASS_EXPORT(tkacheva_headman)

using boost::archive::archive_flags;

tkacheva_group::tkacheva_group()
{
}

tkacheva_group::~tkacheva_group()
{
}

void tkacheva_group::load(const char* filename) {
    ifstream fin;
    fin.open(filename, ios::binary);
    if (fin.is_open()) {
        if (fin.peek() != EOF) {
            boost::archive::text_iarchive load(fin, archive_flags::no_header);
            load >> group;
        }
        fin.close();
    }
}

void tkacheva_group::save(const char* filename) {
    std::ofstream out(filename, ios::binary);
    boost::archive::text_oarchive ar(out, archive_flags::no_header);
    ar << group;
}

int tkacheva_group::get_size()
{
    return (int)group.size();
}

void tkacheva_group::delete_student(int index)
{
    group.erase(group.begin() + index, group.begin() + index + 1);
}

void tkacheva_group::add_student(shared_ptr<tkacheva_student> s)
{
    group.push_back(s);
}

shared_ptr<tkacheva_student> tkacheva_group::get(int i)
{
    return group[i];
}