int FCFS()
{
    cout << "This is FCFS CPU scheduling algorithm" << endl;
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
    int ct[n];
    ct[0] = p[0].bt + p[0].at;
    for (int i = 1; i < n; i++)
    {
        if (p[i].at <= ct[i - 1])
        {
            ct[i] = ct[i - 1] + p[i].bt;
        }
        else
        {
            ct[i] = p[i].at + p[i].bt;
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
    cout << "Output from FCFS scheduling algorithm:" << endl;
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
    cout << "Gantt chart:" << endl;
    for (int i = 0; i < n; i++)
    {
        if (i > 0 && p[i].at > ct[i - 1])
        {
            cout << "|t=" << ct[i - 1] << "   CPU idle    t=" << p[i].at;
            cout << "|t=" << p[i].at << "   P" << p[i].id << "    t=" << ct[i];
        }
        else
            cout << "|t=" << ct[i] - p[i].bt << "   P" << p[i].id << "    t=" << ct[i];
    }
    cout << "|" << endl
         << endl;
    float avgTAT = (float)total_TAT / (float)n;
    float avgWT = (float)total_WT / (float)n;
    cout << "Average TAT: " << avgTAT << endl
         << "Average WT: " << avgWT << endl;
    return 0;
}
