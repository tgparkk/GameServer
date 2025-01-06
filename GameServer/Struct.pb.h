// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Struct.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_Struct_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_Struct_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3021000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3021012 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
#include "Enum.pb.h"
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_Struct_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_Struct_2eproto {
  static const uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_Struct_2eproto;
namespace Protocol {
class BuffData;
struct BuffDataDefaultTypeInternal;
extern BuffDataDefaultTypeInternal _BuffData_default_instance_;
}  // namespace Protocol
PROTOBUF_NAMESPACE_OPEN
template<> ::Protocol::BuffData* Arena::CreateMaybeMessage<::Protocol::BuffData>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace Protocol {

// ===================================================================

class BuffData final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:Protocol.BuffData) */ {
 public:
  inline BuffData() : BuffData(nullptr) {}
  ~BuffData() override;
  explicit PROTOBUF_CONSTEXPR BuffData(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  BuffData(const BuffData& from);
  BuffData(BuffData&& from) noexcept
    : BuffData() {
    *this = ::std::move(from);
  }

  inline BuffData& operator=(const BuffData& from) {
    CopyFrom(from);
    return *this;
  }
  inline BuffData& operator=(BuffData&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const BuffData& default_instance() {
    return *internal_default_instance();
  }
  static inline const BuffData* internal_default_instance() {
    return reinterpret_cast<const BuffData*>(
               &_BuffData_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(BuffData& a, BuffData& b) {
    a.Swap(&b);
  }
  inline void Swap(BuffData* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(BuffData* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  BuffData* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<BuffData>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const BuffData& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const BuffData& from) {
    BuffData::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::PROTOBUF_NAMESPACE_ID::Arena* arena, bool is_message_owned);
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(BuffData* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "Protocol.BuffData";
  }
  protected:
  explicit BuffData(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kVictimsFieldNumber = 3,
    kBuffIdFieldNumber = 1,
    kRemainTimeFieldNumber = 2,
  };
  // repeated uint64 victims = 3;
  int victims_size() const;
  private:
  int _internal_victims_size() const;
  public:
  void clear_victims();
  private:
  uint64_t _internal_victims(int index) const;
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField< uint64_t >&
      _internal_victims() const;
  void _internal_add_victims(uint64_t value);
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< uint64_t >*
      _internal_mutable_victims();
  public:
  uint64_t victims(int index) const;
  void set_victims(int index, uint64_t value);
  void add_victims(uint64_t value);
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField< uint64_t >&
      victims() const;
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< uint64_t >*
      mutable_victims();

  // uint64 buffId = 1;
  void clear_buffid();
  uint64_t buffid() const;
  void set_buffid(uint64_t value);
  private:
  uint64_t _internal_buffid() const;
  void _internal_set_buffid(uint64_t value);
  public:

  // float remainTime = 2;
  void clear_remaintime();
  float remaintime() const;
  void set_remaintime(float value);
  private:
  float _internal_remaintime() const;
  void _internal_set_remaintime(float value);
  public:

  // @@protoc_insertion_point(class_scope:Protocol.BuffData)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    ::PROTOBUF_NAMESPACE_ID::RepeatedField< uint64_t > victims_;
    mutable std::atomic<int> _victims_cached_byte_size_;
    uint64_t buffid_;
    float remaintime_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_Struct_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// BuffData

// uint64 buffId = 1;
inline void BuffData::clear_buffid() {
  _impl_.buffid_ = uint64_t{0u};
}
inline uint64_t BuffData::_internal_buffid() const {
  return _impl_.buffid_;
}
inline uint64_t BuffData::buffid() const {
  // @@protoc_insertion_point(field_get:Protocol.BuffData.buffId)
  return _internal_buffid();
}
inline void BuffData::_internal_set_buffid(uint64_t value) {
  
  _impl_.buffid_ = value;
}
inline void BuffData::set_buffid(uint64_t value) {
  _internal_set_buffid(value);
  // @@protoc_insertion_point(field_set:Protocol.BuffData.buffId)
}

// float remainTime = 2;
inline void BuffData::clear_remaintime() {
  _impl_.remaintime_ = 0;
}
inline float BuffData::_internal_remaintime() const {
  return _impl_.remaintime_;
}
inline float BuffData::remaintime() const {
  // @@protoc_insertion_point(field_get:Protocol.BuffData.remainTime)
  return _internal_remaintime();
}
inline void BuffData::_internal_set_remaintime(float value) {
  
  _impl_.remaintime_ = value;
}
inline void BuffData::set_remaintime(float value) {
  _internal_set_remaintime(value);
  // @@protoc_insertion_point(field_set:Protocol.BuffData.remainTime)
}

// repeated uint64 victims = 3;
inline int BuffData::_internal_victims_size() const {
  return _impl_.victims_.size();
}
inline int BuffData::victims_size() const {
  return _internal_victims_size();
}
inline void BuffData::clear_victims() {
  _impl_.victims_.Clear();
}
inline uint64_t BuffData::_internal_victims(int index) const {
  return _impl_.victims_.Get(index);
}
inline uint64_t BuffData::victims(int index) const {
  // @@protoc_insertion_point(field_get:Protocol.BuffData.victims)
  return _internal_victims(index);
}
inline void BuffData::set_victims(int index, uint64_t value) {
  _impl_.victims_.Set(index, value);
  // @@protoc_insertion_point(field_set:Protocol.BuffData.victims)
}
inline void BuffData::_internal_add_victims(uint64_t value) {
  _impl_.victims_.Add(value);
}
inline void BuffData::add_victims(uint64_t value) {
  _internal_add_victims(value);
  // @@protoc_insertion_point(field_add:Protocol.BuffData.victims)
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< uint64_t >&
BuffData::_internal_victims() const {
  return _impl_.victims_;
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< uint64_t >&
BuffData::victims() const {
  // @@protoc_insertion_point(field_list:Protocol.BuffData.victims)
  return _internal_victims();
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< uint64_t >*
BuffData::_internal_mutable_victims() {
  return &_impl_.victims_;
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< uint64_t >*
BuffData::mutable_victims() {
  // @@protoc_insertion_point(field_mutable_list:Protocol.BuffData.victims)
  return _internal_mutable_victims();
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace Protocol

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_Struct_2eproto
