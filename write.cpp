bool over_write(vector<vector<string> >& List, map<string, int>& Dictionary)
    vector<vector<string> > L = List;
    map<string, int> d = Dictionary;
    for (auto& [key, value] : d) {
        if (key == "DRINKS") {
            L[0][2] = to_string(stoi(L[0][2]) - value);
          else if (key == "CHIPS") {
            L[1][2] = to_string(stoi(L[1][2]) - value);
        } else if (key == "CHOBR") {
            L[1][2] = to_string(stoi(L[1][2]) - value);
		  else if (key == "GUM") {
            L[1][2] = to_string(stoi(L[1][2]) - value);
        } else {
            L[2][2] = to_string(stoi(L[2][2]) - value);
        }
    }
    cout << "\nRemaining Stock Products:\n";
    for (auto& each : L) {
        cout << each[0] << "," << each[1] << "," << each[2] << endl;
    }
    
    ofstream files;
    files.open("products.txt", ios::out); 
    for (auto& each : L) {
        files << each[0] << "," << each[1] << "," << each[2] << endl;
    }
    files.close();
}
