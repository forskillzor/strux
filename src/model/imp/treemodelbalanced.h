#pragma once

#include <model/model.h>

class TreeModelBalanced : public Model
{
public:
    explicit TreeModelBalanced();
    void setRoot(ModelItem* item) override;
    void addItem(ModelItem* item) override;
    void removeItem() override;
};
