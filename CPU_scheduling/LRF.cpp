int LRF()
{
    cout << "This is SJF CPU scheduling algorithm" << endl;
    struct process
    {
        int id;
        int at;
        int bt;
    };
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;
    struct process p[n];
    cout << "Enter the id, at and bt respectively: \n";
    int minTime = INT8_MAX;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i].id >> p[i].at >> p[i].bt;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (p[i].at > p[j].at)
            {
                swap(p[i], p[j]);
            }
        }
    }
    cout << "Sorted:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << p[i].at << " " << p[i].bt << endl;
    }
    int check[n] = {0};
    int time = p[0].at;
    int complete = 0;
    int ct[n];
    while (complete < n)
    {
        int pid = -1;
        int maxBT = -1;
        for (int j = 0; j < n; j++)
        {
            if (check[j] == 0 && p[j].at <= time && maxBT < p[j].bt)
            {
                maxBT = p[j].bt;
                pid = j;
            }
        }
        if (pid != -1)
        {
            check[pid] = 1;
            time = time + maxBT;
            ct[pid] = time;
            complete++;
            cout << "At t= " << time << "Process " << pid << " is completed" << endl;
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                int id = p[i].id;
                if (check[id] == 0)
                {
                    time = p[i].at;
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << ct[i] << " " << p[i].at << endl;
    }
    int total_TAT = 0, total_WT = 0;
    int tat[n], wt[n];
    for (int i = 0; i < n; i++)
    {
        tat[i] = ct[i] - p[i].at;
        wt[i] = tat[i] - p[i].bt;
        total_TAT += tat[i];
        total_WT += wt[i];
    }
    cout << "Input:" << endl;
    cout << endl;
    cout << "P.No"
         << "\t"
         << "AT"
         << "\t"
         << "BT" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << p[i].id << "\t" << p[i].at << "\t" << p[i].bt << endl;
    }
    cout << endl;
    cout << "Output from SJF scheduling algorithm:" << endl;
    cout << endl;
    cout << "TAT"
         << "\t"
         << "WT" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << tat[i] << "\t" << wt[i] << endl;
    }
    cout << endl;
    float avgTAT = (float)total_TAT / (float)n;
    float avgWT = (float)total_WT / (float)n;
    cout << "Average TAT: " << avgTAT << endl
         << "Average WT: " << avgWT << endl;
    return 0;
}
