#ifndef VIEWMODEL_H
#define VIEWMODEL_H

/*******************************
 * Interface ViewModel
 *******************************/

class ViewModel
{
public:
    ViewModel();
    virtual void apply() = 0;
};

/*******************************
 * Interface ViewModel
 *******************************/

class ViewTree : public ViewModel
{
public: ViewTree();
    virtual void apply() override;
};

#endif // VIEWMODEL_H
