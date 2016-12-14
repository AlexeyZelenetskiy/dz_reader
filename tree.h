#ifndef TREE_H
#define TREE_H

#include <locale>   //  у меня и без него норм работает, но мб нужен
#include <QString>
#include <memory>

using namespace std;

class tree
{
    struct Node {
        QString name;
        QString data;
        QString attribute;
        shared_ptr<Node> son;
        shared_ptr<Node> brother;

        Node() {}

        Node(QString name, QString data, QString attribute, shared_ptr<Node> son = shared_ptr<Node>(nullptr), shared_ptr<Node> brother = shared_ptr<Node>(nullptr))
            : name(name), data(data), son(son), brother(brother), attribute(attribute) {}

        Node(const Node & node)
            : name(node.name), data(node.data), attribute(node.attribute), son(node.son), brother(node.brother) {}
    };

     shared_ptr<Node> root;
public:
    tree() {}
    tree(QString & xml)
        : root(new Node(firstElement(xml).name, "", firstElement(xml).attribute))
    {
        _xml = xml;
        pars(crop(xml, *root), *root);
    }

    shared_ptr<Node> getById(QString _name, shared_ptr<Node> _root = shared_ptr<Node>(nullptr));
    QString body__();
private:
    QString _xml;
    void pars(QString  xml, Node & node);
    Node firstElement(const QString & xml);
    QString crop(QString & xml, Node & item);
};

#endif // TREE_H
