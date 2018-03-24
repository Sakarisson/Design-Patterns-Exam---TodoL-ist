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
    int _date; // For simplicity, date is an int. For now, assume UNIX epoch
    int _priority; // Also, priority is int for simplicity. Should be enum
};

class Renderer {
public:
    virtual std::string render(std::vector<Task*>) const = 0;
};

class Numbered : public Renderer {
public:
    std::string render(std::vector<Task*> tasks) const override {
        std::string rendered = "";
        int counter = 0;
        for (auto task : tasks) {
            rendered += std::to_string(++counter) + ". " + task->getDescription() + " Due: " + std::to_string(task->getDate()) + " Priority: " + std::to_string(task->getPriority()) + "\n";
        }
        return rendered;
    }
};

class Bulleted : public Renderer {
public:
    std::string render(std::vector<Task*> tasks) const override {
        std::string rendered = "";
        for (auto task : tasks) {
            rendered += "* " + task->getDescription() + " Due: " + std::to_string(task->getDate()) + " Priority: " + std::to_string(task->getPriority()) + "\n";
        }
        return rendered;
    }
};

class OrderBy {
public:
    virtual std::vector<Task*> order(std::vector<Task*>) = 0;
};

class OrderByDate : public OrderBy {
public:
    std::vector<Task*> order(std::vector<Task*> unorderedList) override {
        std::vector<Task*> orderedList;
        // Sort by date into orderedList
        return orderedList;
    }
};

class OrderByPriority : public OrderBy {
public:
    std::vector<Task*> order(std::vector<Task*> unorderedList) override {
        std::vector<Task*> orderedList;
        // Sort by priority into orderedList
        return orderedList;
    }
};

class Unordered : public OrderBy {
public:
    std::vector<Task*> order(std::vector<Task*> unorderedList) override {
        return unorderedList;
    }
};

class OrderAlphabetically : public OrderBy {
public:
    std::vector<Task*> order(std::vector<Task*> unorderedList) override {
        std::vector<Task*> orderedList;
        // Sort alphabetically into orderedList
        return orderedList;
    }
};

class Frontend {
public:
    Frontend(Renderer* renderer, OrderBy* orderBy, std::vector<Task*> tasks) {
        _renderer = renderer;
        _orderBy = orderBy;
        _tasks = tasks;
    }

    void addTask(Task* task) {
        _tasks.push_back(task);
    }

    bool removeTask(int index) {
        // Remove task at index
        bool taskRemoved = true; // Will be false if operation fails
        return taskRemoved;
    }

    void showList() {
        std::cout << _renderer->render(_orderBy->order(_tasks));
    }

private:
    Renderer* _renderer;
    OrderBy* _orderBy;
    std::vector<Task*> _tasks;
};

int main() {
    std::vector<Task*> tasks;
    tasks.push_back(new Task("Buy groceries", 1371686400, 3));
    tasks.push_back(new Task("Take the DT063G exam", 1371686400, 2));
    tasks.push_back(new Task("Submit the labs", 1371859200, 2));
    tasks.push_back(new Task("Buy movie tickets", 1371254400, 1));
    Frontend front(new Bulleted(), new Unordered(), tasks);
    front.showList();
    return 0;
}
