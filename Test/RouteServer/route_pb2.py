# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: route.proto

from google.protobuf.internal import enum_type_wrapper
from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from google.protobuf import reflection as _reflection
from google.protobuf import descriptor_pb2
# @@protoc_insertion_point(imports)




DESCRIPTOR = _descriptor.FileDescriptor(
  name='route.proto',
  package='DFMS.ROUTE',
  serialized_pb='\n\x0broute.proto\x12\nDFMS.ROUTE\"\x19\n\x17getLatestVersionRequest\"Z\n\x18getLatestVersionResponse\x12\x11\n\tversionNo\x18\x01 \x01(\t\x12\x18\n\x10versionUpdateMsg\x18\x02 \x01(\t\x12\x11\n\terrorCode\x18\x03 \x01(\r\"J\n\x10userLoginRequest\x12\x10\n\x08username\x18\x01 \x01(\t\x12\x10\n\x08password\x18\x02 \x01(\t\x12\x12\n\nmacAddress\x18\x03 \x01(\t\"^\n\x11userLoginResponse\x12\x10\n\x08username\x18\x01 \x01(\t\x12\x11\n\tsessionId\x18\x02 \x01(\t\x12\x11\n\tloginTime\x18\x03 \x01(\x04\x12\x11\n\terrorCode\x18\x04 \x01(\r\"o\n\x05tFile\x12\x10\n\x08\x66ileName\x18\x01 \x01(\t\x12\'\n\x08\x66ileType\x18\x02 \x01(\x0e\x32\x15.DFMS.ROUTE.eFileType\x12+\n\nfilePermis\x18\x03 \x01(\x0e\x32\x17.DFMS.ROUTE.eFilePermis\"I\n\x16getDirFilesNameRequest\x12\r\n\x05reqId\x18\x01 \x01(\r\x12\x10\n\x08\x61uthUUID\x18\x02 \x01(\t\x12\x0e\n\x06\x64irStr\x18\x03 \x01(\t\"m\n\x17getDirFilesNameResponse\x12\r\n\x05reqId\x18\x01 \x01(\r\x12\x0e\n\x06\x64irStr\x18\x02 \x01(\t\x12 \n\x05\x66iles\x18\x03 \x03(\x0b\x32\x11.DFMS.ROUTE.tFile\x12\x11\n\terrorCode\x18\x04 \x01(\r*9\n\teFileType\x12\x0c\n\x08\x65\x44irType\x10\x00\x12\x0c\n\x08\x65\x44ocType\x10\x01\x12\x10\n\x0c\x65GeneralType\x10\x02*B\n\x0b\x65\x46ilePermis\x12\x0b\n\x07\x65\x44\x65nied\x10\x00\x12\r\n\teReadOnly\x10\x01\x12\x0e\n\neWriteOnly\x10\x02\x12\x07\n\x03\x65RW\x10\x03')

_EFILETYPE = _descriptor.EnumDescriptor(
  name='eFileType',
  full_name='DFMS.ROUTE.eFileType',
  filename=None,
  file=DESCRIPTOR,
  values=[
    _descriptor.EnumValueDescriptor(
      name='eDirType', index=0, number=0,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='eDocType', index=1, number=1,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='eGeneralType', index=2, number=2,
      options=None,
      type=None),
  ],
  containing_type=None,
  options=None,
  serialized_start=617,
  serialized_end=674,
)

eFileType = enum_type_wrapper.EnumTypeWrapper(_EFILETYPE)
_EFILEPERMIS = _descriptor.EnumDescriptor(
  name='eFilePermis',
  full_name='DFMS.ROUTE.eFilePermis',
  filename=None,
  file=DESCRIPTOR,
  values=[
    _descriptor.EnumValueDescriptor(
      name='eDenied', index=0, number=0,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='eReadOnly', index=1, number=1,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='eWriteOnly', index=2, number=2,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='eRW', index=3, number=3,
      options=None,
      type=None),
  ],
  containing_type=None,
  options=None,
  serialized_start=676,
  serialized_end=742,
)

eFilePermis = enum_type_wrapper.EnumTypeWrapper(_EFILEPERMIS)
eDirType = 0
eDocType = 1
eGeneralType = 2
eDenied = 0
eReadOnly = 1
eWriteOnly = 2
eRW = 3



_GETLATESTVERSIONREQUEST = _descriptor.Descriptor(
  name='getLatestVersionRequest',
  full_name='DFMS.ROUTE.getLatestVersionRequest',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  options=None,
  is_extendable=False,
  extension_ranges=[],
  serialized_start=27,
  serialized_end=52,
)


_GETLATESTVERSIONRESPONSE = _descriptor.Descriptor(
  name='getLatestVersionResponse',
  full_name='DFMS.ROUTE.getLatestVersionResponse',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='versionNo', full_name='DFMS.ROUTE.getLatestVersionResponse.versionNo', index=0,
      number=1, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=unicode("", "utf-8"),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='versionUpdateMsg', full_name='DFMS.ROUTE.getLatestVersionResponse.versionUpdateMsg', index=1,
      number=2, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=unicode("", "utf-8"),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='errorCode', full_name='DFMS.ROUTE.getLatestVersionResponse.errorCode', index=2,
      number=3, type=13, cpp_type=3, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  options=None,
  is_extendable=False,
  extension_ranges=[],
  serialized_start=54,
  serialized_end=144,
)


_USERLOGINREQUEST = _descriptor.Descriptor(
  name='userLoginRequest',
  full_name='DFMS.ROUTE.userLoginRequest',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='username', full_name='DFMS.ROUTE.userLoginRequest.username', index=0,
      number=1, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=unicode("", "utf-8"),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='password', full_name='DFMS.ROUTE.userLoginRequest.password', index=1,
      number=2, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=unicode("", "utf-8"),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='macAddress', full_name='DFMS.ROUTE.userLoginRequest.macAddress', index=2,
      number=3, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=unicode("", "utf-8"),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  options=None,
  is_extendable=False,
  extension_ranges=[],
  serialized_start=146,
  serialized_end=220,
)


_USERLOGINRESPONSE = _descriptor.Descriptor(
  name='userLoginResponse',
  full_name='DFMS.ROUTE.userLoginResponse',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='username', full_name='DFMS.ROUTE.userLoginResponse.username', index=0,
      number=1, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=unicode("", "utf-8"),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='sessionId', full_name='DFMS.ROUTE.userLoginResponse.sessionId', index=1,
      number=2, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=unicode("", "utf-8"),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='loginTime', full_name='DFMS.ROUTE.userLoginResponse.loginTime', index=2,
      number=3, type=4, cpp_type=4, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='errorCode', full_name='DFMS.ROUTE.userLoginResponse.errorCode', index=3,
      number=4, type=13, cpp_type=3, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  options=None,
  is_extendable=False,
  extension_ranges=[],
  serialized_start=222,
  serialized_end=316,
)


_TFILE = _descriptor.Descriptor(
  name='tFile',
  full_name='DFMS.ROUTE.tFile',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='fileName', full_name='DFMS.ROUTE.tFile.fileName', index=0,
      number=1, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=unicode("", "utf-8"),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='fileType', full_name='DFMS.ROUTE.tFile.fileType', index=1,
      number=2, type=14, cpp_type=8, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='filePermis', full_name='DFMS.ROUTE.tFile.filePermis', index=2,
      number=3, type=14, cpp_type=8, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  options=None,
  is_extendable=False,
  extension_ranges=[],
  serialized_start=318,
  serialized_end=429,
)


_GETDIRFILESNAMEREQUEST = _descriptor.Descriptor(
  name='getDirFilesNameRequest',
  full_name='DFMS.ROUTE.getDirFilesNameRequest',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='reqId', full_name='DFMS.ROUTE.getDirFilesNameRequest.reqId', index=0,
      number=1, type=13, cpp_type=3, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='authUUID', full_name='DFMS.ROUTE.getDirFilesNameRequest.authUUID', index=1,
      number=2, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=unicode("", "utf-8"),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='dirStr', full_name='DFMS.ROUTE.getDirFilesNameRequest.dirStr', index=2,
      number=3, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=unicode("", "utf-8"),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  options=None,
  is_extendable=False,
  extension_ranges=[],
  serialized_start=431,
  serialized_end=504,
)


_GETDIRFILESNAMERESPONSE = _descriptor.Descriptor(
  name='getDirFilesNameResponse',
  full_name='DFMS.ROUTE.getDirFilesNameResponse',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='reqId', full_name='DFMS.ROUTE.getDirFilesNameResponse.reqId', index=0,
      number=1, type=13, cpp_type=3, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='dirStr', full_name='DFMS.ROUTE.getDirFilesNameResponse.dirStr', index=1,
      number=2, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=unicode("", "utf-8"),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='files', full_name='DFMS.ROUTE.getDirFilesNameResponse.files', index=2,
      number=3, type=11, cpp_type=10, label=3,
      has_default_value=False, default_value=[],
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='errorCode', full_name='DFMS.ROUTE.getDirFilesNameResponse.errorCode', index=3,
      number=4, type=13, cpp_type=3, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  options=None,
  is_extendable=False,
  extension_ranges=[],
  serialized_start=506,
  serialized_end=615,
)

_TFILE.fields_by_name['fileType'].enum_type = _EFILETYPE
_TFILE.fields_by_name['filePermis'].enum_type = _EFILEPERMIS
_GETDIRFILESNAMERESPONSE.fields_by_name['files'].message_type = _TFILE
DESCRIPTOR.message_types_by_name['getLatestVersionRequest'] = _GETLATESTVERSIONREQUEST
DESCRIPTOR.message_types_by_name['getLatestVersionResponse'] = _GETLATESTVERSIONRESPONSE
DESCRIPTOR.message_types_by_name['userLoginRequest'] = _USERLOGINREQUEST
DESCRIPTOR.message_types_by_name['userLoginResponse'] = _USERLOGINRESPONSE
DESCRIPTOR.message_types_by_name['tFile'] = _TFILE
DESCRIPTOR.message_types_by_name['getDirFilesNameRequest'] = _GETDIRFILESNAMEREQUEST
DESCRIPTOR.message_types_by_name['getDirFilesNameResponse'] = _GETDIRFILESNAMERESPONSE

class getLatestVersionRequest(_message.Message):
  __metaclass__ = _reflection.GeneratedProtocolMessageType
  DESCRIPTOR = _GETLATESTVERSIONREQUEST

  # @@protoc_insertion_point(class_scope:DFMS.ROUTE.getLatestVersionRequest)

class getLatestVersionResponse(_message.Message):
  __metaclass__ = _reflection.GeneratedProtocolMessageType
  DESCRIPTOR = _GETLATESTVERSIONRESPONSE

  # @@protoc_insertion_point(class_scope:DFMS.ROUTE.getLatestVersionResponse)

class userLoginRequest(_message.Message):
  __metaclass__ = _reflection.GeneratedProtocolMessageType
  DESCRIPTOR = _USERLOGINREQUEST

  # @@protoc_insertion_point(class_scope:DFMS.ROUTE.userLoginRequest)

class userLoginResponse(_message.Message):
  __metaclass__ = _reflection.GeneratedProtocolMessageType
  DESCRIPTOR = _USERLOGINRESPONSE

  # @@protoc_insertion_point(class_scope:DFMS.ROUTE.userLoginResponse)

class tFile(_message.Message):
  __metaclass__ = _reflection.GeneratedProtocolMessageType
  DESCRIPTOR = _TFILE

  # @@protoc_insertion_point(class_scope:DFMS.ROUTE.tFile)

class getDirFilesNameRequest(_message.Message):
  __metaclass__ = _reflection.GeneratedProtocolMessageType
  DESCRIPTOR = _GETDIRFILESNAMEREQUEST

  # @@protoc_insertion_point(class_scope:DFMS.ROUTE.getDirFilesNameRequest)

class getDirFilesNameResponse(_message.Message):
  __metaclass__ = _reflection.GeneratedProtocolMessageType
  DESCRIPTOR = _GETDIRFILESNAMERESPONSE

  # @@protoc_insertion_point(class_scope:DFMS.ROUTE.getDirFilesNameResponse)


# @@protoc_insertion_point(module_scope)