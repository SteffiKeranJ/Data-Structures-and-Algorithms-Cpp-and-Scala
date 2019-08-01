vector<string> readBinaryWatch(int num) {
    vector<string> rs;
// iterate over all possible hour and minute combinations
    for (int h = 0; h < 12; h++)
    for (int m = 0; m < 60; m++)
        if (bitset<10>(h << 6 | m).count() == num)
	// if the minute is less than 10, add a leading 0
            rs.emplace_back(to_string(h) + (m < 10 ? ":0" : ":") + to_string(m));
    return rs;
}
