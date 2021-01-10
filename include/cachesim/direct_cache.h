// Copyright 2020 Juan Yaguaro
#ifndef CACHESIM_DIRECT_CACHE_H_
#define CACHESIM_DIRECT_CACHE_H_

#include <cachesim/cache.h>

#include <iostream>
#include <vector>
namespace cachesim {

// class direct_cache
class direct_cache : public cache {
 public:
  // ctor
  direct_cache();
  explicit direct_cache(const std::size_t& size, const std::size_t& line_size,
                        emplace_policy& policy);
  ~direct_cache() = default;
  // accessors
  bool exists() const noexcept override final { return true; }
  // mutators
  void clear() override final {}
  void resize(const std::size_t& size,
              const std::size_t& line_size) override final {}
  void emplace(const int& value) override final {}

 private:
  std::vector<int> items_;
};

direct_cache::direct_cache() : cache(), items_(1, empty_space) {}

direct_cache::direct_cache(const std::size_t& size,
                           const std::size_t& line_size, emplace_policy& policy)
    : cache(size, line_size, policy), items_(size / line_size, empty_space) {}

}  // namespace cachesim

#endif  // CACHESIM_DIRECT_CACHE_H_
