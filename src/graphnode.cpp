#include <iostream>
#include "graphedge.h"
#include "graphnode.h"

GraphNode::GraphNode(int id)
{
    _id = id;
}

GraphNode::~GraphNode()
{
    //// STUDENT CODE
    //// Task 0 0000 this may not be for task 0, it might be task 5

    //delete _chatBot;

    ////
    //// EOF STUDENT CODE
}

void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(GraphEdge *edge)
{
    _parentEdges.push_back(edge);
}
// Task 4 4444 Altering signatures to compensate for new data structures
void GraphNode::AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge)
{
    _childEdges.push_back(std::move(edge));
}

//// STUDENT CODE
////
// Task 5 Change method signature
//void GraphNode::MoveChatBotHere(std::unique_ptr<ChatBot> chatbot)
void GraphNode::MoveChatBotHere(ChatBot chatbot)
{
    //_chatBot = chatbot;
    _chatBot = std::move(chatbot);
    _chatBot.SetCurrentNode(this);

}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{
    newNode->MoveChatBotHere(std::move(_chatBot));

}
////
//// EOF STUDENT CODE

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index)
{
    //// STUDENT CODE
    ////

    //  Task 4 4444 Alter return
    return _childEdges.at(index).get();

    ////
    //// EOF STUDENT CODE
}