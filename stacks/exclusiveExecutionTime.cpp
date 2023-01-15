std::vector<int> ExclusiveTime(int n, std::vector<std::string> logs)
{
    std::stack<Log> logStack;
    std::vector<int> result(n);
    for (std::string content : logs)
    {
        // Extract the event details from the content(string)
        Log myEvent(content);
        if (myEvent.isStart)
        {
            // Push the event details to the event stack
            logStack.push(myEvent);
        }
        else
        {
            // Pop the event details from the event stack
            Log myTop = logStack.top();
            logStack.pop();
            // Add the execution time of the current function in the actual result
            result[myTop.id] += (myEvent.time - myTop.time + 1);
            // If the logstack is not empty, subtract the current child function execution time from the parent function
            if (!logStack.empty())
            {
                result[logStack.top().id] -= (myEvent.time - myTop.time + 1);
            }
        }
    }
    return result;
}
