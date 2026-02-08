/*
 * CS106L Assignment 2: Marriage Pact
 * Created by Haven Whitney with modifications by Fabio Ibanez & Jacob Roberts-Baca.
 *
 * Welcome to Assignment 2 of CS106L! Please complete each STUDENT TODO
 * in this file. You do not need to modify any other files.
 *
 */

#include <fstream>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <unordered_set>
#include <sstream>

std::string kYourName = "Aaron Coleman"; // Don't forget to change this!

/**
 * Takes in a file name and returns a set containing all of the applicant names as a set.
 *
 * @param filename  The name of the file to read.
 *                  Each line of the file will be a single applicant's name.
 * @returns         A set of all applicant names read from the file.
 *
 * @remark Feel free to change the return type of this function (and the function
 * below it) to use a `std::unordered_set` instead. If you do so, make sure
 * to also change the corresponding functions in `utils.h`.
 */
std::set<std::string> get_applicants(std::string filename) {
  // STUDENT TODO: Implement this function.
  std::ifstream inFile(filename);
  std::set<std::string> names;
  std::string name;
  if (inFile.is_open()) {
    while (std::getline(inFile, name))
    {
      names.insert(name);
    }
  }
  return names;
}

bool is_match(const std::string& name1, const std::string& name2) {
  auto p1 = name1.find(' ');
    auto p2 = name2.find(' ');

    if (p1 == std::string::npos ||
        p2 == std::string::npos)
        return false;

    return name1[0] == name2[0] &&
           name1[p1+1] == name2[p2+1];
}
/**
 * Takes in a set of student names by reference and returns a queue of names
 * that match the given student name.
 *
 * @param name      The returned queue of names should have the same initials as this name.
 * @param students  The set of student names.
 * @return          A queue containing pointers to each matching name.
 */
std::queue<const std::string*> find_matches(std::string name, std::set<std::string>& students) {
  // STUDENT TODO: Implement this function.
  std::queue<const std::string*> result;
  for (const auto& student: students){
    if (is_match(name, student)) {
      result.push(&student);
    }
  }
  return result;
}

/**
 * Takes in a queue of pointers to possible matches and determines the one true match!
 *
 * You can implement this function however you'd like, but try to do something a bit
 * more complicated than a simple `pop()`.
 *
 * @param matches The queue of possible matches.
 * @return        Your magical one true love.
 *                Will return "NO MATCHES FOUND." if `matches` is empty.
 */
std::string get_match(std::queue<const std::string*>& matches) {
  if (matches.empty()) {
    return "NO MATCHES FOUND.";
  }
  // STUDENT TODO: Implement this function.
  const std::string result = *(matches.front());
  matches.pop();
  return result;
}

/* #### Please don't remove this line! #### */
#include "autograder/utils.hpp"
