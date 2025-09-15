#include <iostream>
#include <vector>
#include <string>
using namespace std;


class User {
public:
    int userId;
    string name;
    string email;
};

class Profile {
public:
    int profileId;
    int userId;  
};

class Movie {
public:
    int movieId;
    string title;
    string genre;
};

class Actor {
public:
    int actorId;
    string name;
};

class Review {
public:
    int reviewId;
    int userId;
    int movieId;
    int rating;
};

class List {
public:
    int listId;
    int userId;
    string title;
    vector<int> movieIds; 
};

class Notification {
public:
    int notificationId;
    int userId;
    string message;
};

class Admin {
public:
    int adminId;
    string name;
};

class Recommendation {
public:
    int recId;
    int userId;
    int movieId;
};


void printUser(const User& u) {
    cout << u.userId << " - " << u.name << " (" << u.email << ")\n";
}

void printMovie(const Movie& m) {
    cout << m.movieId << " - " << m.title << " [" << m.genre << "]\n";
}

void printReview(const Review& r) {
    cout << r.reviewId << " - User " << r.userId
        << " rated Movie " << r.movieId
        << " " << r.rating << "/5\n";
}

void printList(const List& l) {
    cout << l.listId << " - " << l.title
        << " (User " << l.userId << ")\n";
    for (int movieId : l.movieIds) {
        cout << "   contains Movie " << movieId << "\n";
    }
}

void printNotification(const Notification& n) {
    cout << n.notificationId << " -> User "
        << n.userId << ": " << n.message << "\n";
}

void printRecommendation(const Recommendation& r) {
    cout << r.recId << " -> User "
        << r.userId << " should watch Movie "
        << r.movieId << "\n";
}

int main() {
    
    Admin admin{ 1, "System Admin" };

    User u1{ 1, "Ahmed", "ahmed@example.com" };
    User u2{ 2, "Sara", "sara@example.com" };

    Movie m1{ 1, "Inception", "Sci-Fi" };
    Movie m2{ 2, "Titanic", "Romance" };

    Review r1{ 1, u1.userId, m1.movieId, 5 };
    Review r2{ 2, u2.userId, m2.movieId, 4 };

    List l1{ 1, u1.userId, "Ahmed's Top Movies", {m1.movieId, m2.movieId} };

    Notification n1{ 1, u1.userId, "New Sci-Fi movie added!" };

    Recommendation rec1{ 1, u2.userId, m1.movieId };
    cout << "Admin: " << admin.name << "\n\n";

    cout << "Users:\n";
    printUser(u1);
    printUser(u2);
    cout << "\n";

    cout << "Movies:\n";
    printMovie(m1);
    printMovie(m2);
    cout << "\n";

    cout << "Reviews:\n";
    printReview(r1);
    printReview(r2);
    cout << "\n";

    cout << "List:\n";
    printList(l1);
    cout << "\n";

    cout << "Notification:\n";
    printNotification(n1);
    cout << "\n";

    cout << "Recommendation:\n";
    printRecommendation(rec1);
    cout << "\n";

    return 0;
}

