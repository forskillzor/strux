#pragma once

#include "model/model.h"

class TreeModel : public Model
{
public:
    explicit TreeModel();
    void setRoot(ModelItem* item) override;
    void addItem(ModelItem* item) override;
    void removeItem() override;
};
