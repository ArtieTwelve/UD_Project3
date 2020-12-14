#ifndef GRAPHNODE_H_
#define GRAPHNODE_H_

#include <vector>
#include <string>
#include <memory>
#include "chatbot.h"


// forward declarations
class GraphEdge;

class GraphNode
{
private:
    //// STUDENT CODE
    ////

    // data handles (owned)
    // Task 4 4444 - change data structure to vector unique_ptrs
    std::vector<std::unique_ptr<GraphEdge>>_childEdges;  // edges to subsequent nodes

    // data handles (not owned)
    // Task 4 4444 - parent edges were not changed to a vector of unique or shared pointers
    // This was done to meet the requirement that the handles not be owned
    std::vector<GraphEdge *> _parentEdges; // edges to preceding nodes

    // Task 5 5555 - refactor Chatbot to an Object
    ChatBot _chatBot;

    ////
    //// EOF STUDENT CODE

    // proprietary members
    int _id;
    std::vector<std::string> _answers;

public:
    // constructor / destructor
    GraphNode(int id);
    ~GraphNode();

    // getter / setter
    int GetID() { return _id; }
    int GetNumberOfChildEdges() { return _childEdges.size(); }
    GraphEdge *GetChildEdgeAtIndex(int index);
    std::vector<std::string> GetAnswers() { return _answers; }
    int GetNumberOfParents() { return _parentEdges.size(); }

    // proprietary functions
    void AddToken(std::string token); // add answers to list
    void AddEdgeToParentNode(GraphEdge *edge);
    // Task 4 Altering signature
    void AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge);
    //void AddEdgeToChildNode(GraphEdge *edge);

    //// STUDENT CODE
    ////
    // Task 5 change signature
    //void MoveChatBotHere(std::unique_ptr<ChatBot> chatBot);
    void MoveChatBotHere(ChatBot chatBot);

    //void MoveChatbotHere(dtdChatBot *chatbot);

    ////
    //// EOF STUDENT CODE

    void MoveChatbotToNewNode(GraphNode *newNode);
};

#endif /* GRAPHNODE_H_ */