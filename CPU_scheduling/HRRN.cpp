int HRRN()
{
    cout << "This is HRRN CPU scheduling algorithm" << endl;
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
    int minTime = INT8_MAX;
    cout << "Enter the id, at and bt respectively: \n";
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
    int check[n] = {0};
    int time = p[0].at;
    int complete = 0;
    int ct[n];
    while (complete < n)
    {
        int pid = -1;
        float HRT = -1;
        for (int j = 0; j < n; j++)
        {
            float response_ratio;
            if (check[j] == 0 && p[j].at <= time)
                response_ratio = (float)(p[j].bt + abs(time - p[j].at)) / (float)p[j].bt;
            if (check[j] == 0 && p[j].at <= time && HRT < response_ratio)
            {
                HRT = response_ratio;
                pid = j;
            }
        }
        if (pid != -1)
        {
            check[pid] = 1;
            time = time + p[pid].bt;
            ct[pid] = time;
            complete++;
            cout << "At t= " << time << " Process " << p[pid].id << " is completed" << endl;
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                if (check[i] == 0)
                {
                    time = p[i].at;
                }
            }
        }
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
    cout << "Output from HRRN scheduling algorithm:" << endl;
    cout << endl;
    cout << "P.No"
         << "\t"
         << "AT"
         << "\t"
         << "BT"
         << "\t"
         << "CT"
         << "\t"
         << "TAT"
         << "\t"
         << "WT" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << p[i].id << "\t" << p[i].at << "\t" << p[i].bt << "\t" << ct[i] << "\t" << tat[i] << "\t" << wt[i] << endl;
    }
    cout << endl;
    float avgTAT = (float)total_TAT / (float)n;
    float avgWT = (float)total_WT / (float)n;
    cout << "Average TAT: " << avgTAT << endl
         << "Average WT: " << avgWT << endl;
    return 0;
}