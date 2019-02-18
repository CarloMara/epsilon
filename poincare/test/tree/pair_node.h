#ifndef POINCARE_TEST_PAIR_NODE_H
#define POINCARE_TEST_PAIR_NODE_H

#include <poincare/tree_node.h>
#include <poincare/tree_handle.h>
#include <poincare/array_builder.h>

namespace Poincare {

class PairNode : public TreeNode {
public:
  virtual size_t size() const override { return sizeof(PairNode); }
  virtual int numberOfChildren() const override { return 2; }
#if POINCARE_TREE_LOG
  virtual void logNodeName(std::ostream & stream) const override {
    stream << "Pair";
  }
#endif
};

class PairByReference : public TreeHandle {
public:
  static PairByReference Builder(TreeHandle t1, TreeHandle t2) {
    void * bufferNode = TreePool::sharedPool()->alloc(sizeof(PairNode));
    PairNode * node = new (bufferNode) PairNode();
    TreeHandle children[2] = {t1, t2};
    TreeHandle h = TreeHandle::BuildWithBasicChildren(node, children, 2);
    return static_cast<PairByReference &>(h);
  }
  PairByReference() = delete;
};

}

#endif
