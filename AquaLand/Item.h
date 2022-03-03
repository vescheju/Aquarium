/**
 * \file Item.h
 *
 * \author Justin Vesche
 *
 * Class that creates an item
 *
 * This class creates a item that can describe
 * any item that we add to the aquarium.
 */

#pragma once
#include<memory>
#include <string>
#include "XmlNode.h"
class CAquarium;
/**
 * Class that creates an item.
 *
 * This class creates items
 * that can be placed in aquarium.
 */
class CItem
{
public:
    /// Default constructor (disabled)
    CItem() = delete;

    /// Copy constructor (disabled)
    CItem(const CItem&) = delete;

	virtual ~CItem();

    /** The X location of the item
     * \returns X location in pixels */
    double GetX() const { return mX; }

    /** The Y location of the item
    * \returns Y location in pixels */
    double GetY() const { return mY; }

    /// Set the item location
    /// \param x X location
    /// \param y Y location
    virtual void SetLocation(double x, double y) { mX = x; mY = y; }

    /// Draw this item
    /// \param graphics Graphics device to draw on
    void Draw(Gdiplus::Graphics* graphics);

    /** Test this item to see if it has been clicked on
     * \param x X location on the aquarium to test
     * \param y Y location on the aquarium to test
     * \return true if clicked on */
    bool HitTest(int x, int y);

    /// Getter for the aquarium
    /// \return constant pointer of mAqarium
    CAquarium* GetAquarium() { return mAquarium; }

    virtual std::shared_ptr<xmlnode::CXmlNode>
        XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node);

    virtual void XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node);

    /// Handle updates for animation
    /// \param elapsed The time since the last update
    virtual void Update(double elapsed) {}

    /// Set the mirror status
    /// \param m New mirror flag
    void SetMirror(bool m) { mMirror = m; }

    /// Get the width of the aquarium
    /// \returns Aquarium width
    double GetWidth() const { return mItemImage->GetWidth(); }

    /// Get the height of the aquarium
    /// \returns Aquarium height
    double GetHeight() const { return mItemImage->GetHeight(); }

private:
    /// The aquarium this item is contained in
    CAquarium* mAquarium;

    // Item location in the aquarium
    double  mX = 0;     ///< X location for the center of the item
    double  mY = 0;     ///< Y location for the center of the item

    /// The image of this fish
    std::unique_ptr<Gdiplus::Bitmap> mItemImage;

    bool mMirror = false;   ///< True mirrors the item image

protected:
    CItem(CAquarium* aquarium, const std::wstring& filename);
};

