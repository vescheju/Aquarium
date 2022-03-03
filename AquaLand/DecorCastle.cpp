/**
 * \file DecorCastle.cpp
 *
 * \author Justin Vesche
 */


#include "pch.h"
#include <string>
#include "DecorCastle.h"

using namespace Gdiplus;
using namespace std;

/// decor filename 
const wstring DecorCastleImageName = L"images/castle.png";

/**
* Constructor
* \param aquarium Aquarium this decor is a member of
*/
CDecorCastle::CDecorCastle(CAquarium* aquarium) :
    CItem(aquarium, DecorCastleImageName)
{
}

/**
 * Save this item to an XML node
 * \param node The node we are going to be a child of
 * \return a shared_ptr of an XmlNode
 */
std::shared_ptr<xmlnode::CXmlNode>
CDecorCastle::XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
    auto itemNode = CItem::XmlSave(node);

    itemNode->SetAttribute(L"type", L"castle");

    return itemNode;
}

