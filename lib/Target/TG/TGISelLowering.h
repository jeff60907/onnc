#pragma once

#include "TGBackend.h"
#include "TargetLowering.h"
#include <memory>
#include <onnx/common/ir.h>

namespace onnc {

class TargetLowering;
class TGBackend;

using MemTable = std::map<std::string, uint64_t>;

class TGTargetLowering : public TargetLowering
{
public:
  TGTargetLowering(TGBackend *pBackend) : TargetLowering(pBackend) {}

  void
  LowerOperation(const ::onnx::Node &node,
                 std::vector<std::unique_ptr<Operator> > &instList) override;

private:
  void ddrScanAndAlloc(MemTable &memTable, ::onnx::Graph &graph);

private:
  Operator *LowerHelper(const ::onnx::Node &node, MemTable &memTabl);
};

} // namespace onnc
