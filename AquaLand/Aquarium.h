/**
 * \file Aquarium.h
 *
 * \author Justin Vesche
 *
 * Class that represents the aquarium.
 *
 * This class stores all the information that represents
 * the drawn out aquarium.
 */

#pragma once

#include<memory>
#include<vector>
#include <string>
#include "XmlNode.h"

class CItem;
class CFishAngler;
 /**
  * This class is responsible for creating the aquarium.
  */

class CAquarium
{
public:
	// Construction
	CAquarium();

	void OnDraw(Gdiplus::Graphics* graphics);

	void Add(std::shared_ptr<CItem> item);

	std::shared_ptr<CItem> HitTest(int x, int y);

	void SendBack(std::shared_ptr<CItem> &item);

	std::shared_ptr<CItem> Collision(CItem* anglerFish);

	void Save(const std::wstring& filename);

	void Load(const std::wstring& filename);

	void Update(double elapsed);

	void Clear();

	/// Get the width of the aquarium
	/// \returns Aquarium width
	int GetWidth() const { return mBackground->GetWidth(); }

	/// Get the height of the aquarium
	/// \returns Aquarium height
	int GetHeight() const { return mBackground->GetHeight(); }

private:
	std::unique_ptr<Gdiplus::Bitmap> mBackground; ///< Background image to use

	/// All of the items to populate our aquarium
	std::vector<std::shared_ptr<CItem> > mItems;

	void XmlItem(const std::shared_ptr<xmlnode::CXmlNode>& node);
};

