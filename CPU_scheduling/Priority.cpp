int Priority()
{
    cout << "This is Priority based preemptive CPU scheduling algorithm" << endl;
    struct process
    {
        int id;
        int at;
        int bt;
        int bt2;
        int in_queue;
        int completed;
        int ct;
        int pri;
    };
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;
    struct process p[n];
    int minTime = INT8_MAX;
    cout << "Enter the id, at, bt and priority respectively: \n";
    for (int i = 0; i < n; i++)
    {
        cin >> p[i].id >> p[i].at >> p[i].bt >> p[i].pri;
        p[i].in_queue = 0;
        p[i].completed = 0;
        p[i].ct = 0;
        p[i].bt2 = p[i].bt;
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
    int timeQuanta = 1;
    int completed = 0;
    int time = p[0].at;
    while (completed < n)
    {
        for (int i = 0; i < n; i++)
        {
            if (p[i].in_queue == 0 && p[i].completed == 0 && p[i].at <= time)
            {
                p[i].in_queue = 1;
                cout << "At time= " << time << " process " << p[i].id << " is enqueued " << endl;
            }
        }
        int minP = 1000, minBTP = -1;
        for (int i = 0; i < n; i++)
        {
            if (p[i].in_queue == 1 && p[i].completed == 0 && p[i].pri < minP)
            {
                minP = p[i].pri;
                minBTP = i;
            }
        }
        if (minBTP != -1)
        {
            int cut = min(timeQuanta, p[minBTP].bt);
            cout << "At time= " << time << " process " << p[minBTP].id << " is processed for time= "
                 << cut << endl;
            p[minBTP].bt -= cut;
            time += cut;
            if (p[minBTP].bt == 0)
            {
                cout << "At time= " << time << " process " << p[minBTP].id << " is completed " << endl;
                completed++;
                p[minBTP].completed = 1;
                p[minBTP].ct = time;
            }
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                if (p[i].in_queue == 0 && p[i].completed == 0)
                {
                    time = p[i].at;
                    break;
                }
            }
        }
    }
    int tat[n], wt[n];
    int total_TAT = 0, total_WT = 0;
    for (int i = 0; i < n; i++)
    {
        tat[i] = p[i].ct - p[i].at;
        wt[i] = tat[i] - p[i].bt2;
        total_TAT += tat[i];
        total_WT += wt[i];
        //cout << wt[i] << endl;
    }
    cout << "Input:" << endl;
    cout << endl;
    cout << "P.No"
         << "\t"
         << "AT"
         << "\t"
         << "BT"
         << "\t"
         << "Priority" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << p[i].id << "\t" << p[i].at << "\t" << p[i].bt2 << "\t" << p[i].pri <<endl;
    }
    cout << endl;
    cout << "Output from Priority based preemptive CPU scheduling algorithm:" << endl;
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
        cout << p[i].id << "\t" << p[i].at << "\t" << p[i].bt2 << "\t" << p[i].ct << "\t" << tat[i] << "\t" << wt[i] << endl;
    }
    cout << endl;
    float avgTAT = (float)total_TAT / (float)n;
    float avgWT = (float)total_WT / (float)n;
    cout << "Average TAT: " << avgTAT << endl
         << "Average WT: " << avgWT << endl;
    return 0;
}