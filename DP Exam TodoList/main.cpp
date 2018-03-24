#include <string>
#include <vector>
#include <iostream>

class Task {
public:
    Task(std::string description, int date, int priority) {
        _description = description;
        _date = date;
        _priority = priority;
    }

    std::string getDescription() const { return _description; }
    int getDate() const { return _date; }
    int getPriority() const { return _priority; }

private:
    std::string _description;
    int _date; // For simplicity, date is an int
    int _priority; // Also, priority is int for simplicity. Should be enum
};

class TaskList {
    virtual std::string render(std::vector<Task*>) const = 0;
};

class Numbered : public TaskList {
    std::string render(std::vector<Task*> tasks) const override {
        std::string rendered = "";
        int counter = 0;
        for (auto task : tasks) {
            rendered += ++counter + ". " + task->getDescription() + " Due: " + std::to_string(task->getDate()) + " Priority: " + std::to_string(task->getPriority()) + "\n";
        }
        return rendered;
    }
};

class Bulleted : public TaskList {
    std::string render(std::vector<Task*> tasks) const override {
        std::string rendered = "";
        for (auto task : tasks) {
            rendered += "* " + task->getDescription() + " Due: " + std::to_string(task->getDate()) + " Priority: " + std::to_string(task->getPriority()) + "\n";
        }
        return rendered;
    }
};

int main() {
    return 0;
}
