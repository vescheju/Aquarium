/**
 * \file FishNemo.cpp
 *
 * \author Justin Vesche
 */

#include "pch.h"
#include <string>
#include "FishNemo.h"


 /// Maximum speed in the X direction in
 /// in pixels per second
const double MaxSpeedX = 80;

/// Min speed in the X direction in
/// in pixels per second
const double MinSpeedX = 60;

/// Maximum speed in the Y direction in
/// in pixels per second
const double MaxSpeedY = 60;

/// Min speed in the Y direction in
/// in pixels per second
const double MinSpeedY = 30;

using namespace Gdiplus;
using namespace std;

/// Fish filename 
const wstring FishNemoImageName = L"images/nemo.png";

/**
* Constructor
* \param aquarium Aquarium this fish is a member of
*/
CFishNemo::CFishNemo(CAquarium* aquarium) :
    CFish(aquarium, FishNemoImageName)
{
    setSpeedX((MinSpeedX + ((double)rand() / RAND_MAX) * (MaxSpeedX - MinSpeedX)));
    setSpeedY((MinSpeedY + ((double)rand() / RAND_MAX) * (MaxSpeedY - MinSpeedY)));
}

/**
 * Save this item to an XML node
 * \param node The node we are going to be a child of
 * \return itemNode a shared_ptr of an XmlNode
 */
std::shared_ptr<xmlnode::CXmlNode>
CFishNemo::XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
    auto itemNode = CFish::XmlSave(node);

    itemNode->SetAttribute(L"type", L"nemo");

    return itemNode;
}


