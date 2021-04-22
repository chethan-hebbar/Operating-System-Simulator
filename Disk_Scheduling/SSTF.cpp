int SSTF()
{
    int tracks, location[1000], initial_track;
    cout << "Enter the number of tracks: ";
    cin >> tracks;
    int m;
    cout << "Enter total number of requests: ";
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cout << "Enter the request: " << i << " : ";
        cin >> location[i];
    }
    cout << "Enter the starting location: ";
    cin >> initial_track;
    int ans = 0;
    vector<int> temp_loc;
    for (int i = 0; i < m; i++)
        temp_loc.push_back(location[i]);
    temp_loc.push_back(initial_track);
    sort(temp_loc.begin(), temp_loc.end());
    int curr;
    for (int i = 0; i < m; i++)
    {
        if (temp_loc[i] == initial_track)
        {
            curr = i;
            break;
        }
    }
    while (temp_loc.size() != 1)
    {
        if (curr == 0)
        {
            cout << "Going to track " << temp_loc[curr + 1] << " 1\n";
            for(auto i : temp_loc) cout << i << " "; cout << "\n";
            ans += abs(temp_loc[curr + 1] - temp_loc[curr]);
            temp_loc.erase(temp_loc.begin() + curr);
            curr++;
            continue;
        }
        if (curr == temp_loc.size() - 1)
        {
            cout << "Going to track " << temp_loc[curr - 1] << " 2\n";
            for(auto i : temp_loc) cout << i << " "; cout << "\n";
            ans += abs(temp_loc[curr - 1] - temp_loc[curr]);
            temp_loc.erase(temp_loc.begin() + curr);
            curr--;
            continue;
        }
        if (abs(temp_loc[curr] - temp_loc[curr - 1]) < abs(temp_loc[curr] - temp_loc[curr + 1]))
        {
            cout << "Going to track " << temp_loc[curr - 1] << " 3\n";
            for(auto i : temp_loc) cout << i << " "; cout << "\n";
            ans += abs(temp_loc[curr - 1] - temp_loc[curr]);
            temp_loc.erase(temp_loc.begin() + curr);
            curr--;
        }
        else
        {
            cout << "Going to track " << temp_loc[curr + 1] << " 4\n";
            for(auto i : temp_loc) cout << i << " "; cout << "\n";
            ans += abs(temp_loc[curr + 1] - temp_loc[curr]);
            temp_loc.erase(temp_loc.begin() + curr);
            curr++;
        }
    }
    return ans;
}
