# generated from rosidl_generator_py/resource/_idl.py.em
# with input from rotor_tm_msgs:msg/FMCommand.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_FMCommand(type):
    """Metaclass of message 'FMCommand'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('rotor_tm_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'rotor_tm_msgs.msg.FMCommand')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__fm_command
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__fm_command
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__fm_command
            cls._TYPE_SUPPORT = module.type_support_msg__msg__fm_command
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__fm_command

            from geometry_msgs.msg import Vector3
            if Vector3.__class__._TYPE_SUPPORT is None:
                Vector3.__class__.__import_type_support__()

            from std_msgs.msg import Header
            if Header.__class__._TYPE_SUPPORT is None:
                Header.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class FMCommand(metaclass=Metaclass_FMCommand):
    """Message class 'FMCommand'."""

    __slots__ = [
        '_header',
        '_thrust',
        '_rlink_thrust',
        '_moments',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'thrust': 'double',
        'rlink_thrust': 'geometry_msgs/Vector3',
        'moments': 'geometry_msgs/Vector3',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Vector3'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Vector3'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        self.thrust = kwargs.get('thrust', float())
        from geometry_msgs.msg import Vector3
        self.rlink_thrust = kwargs.get('rlink_thrust', Vector3())
        from geometry_msgs.msg import Vector3
        self.moments = kwargs.get('moments', Vector3())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.header != other.header:
            return False
        if self.thrust != other.thrust:
            return False
        if self.rlink_thrust != other.rlink_thrust:
            return False
        if self.moments != other.moments:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def header(self):
        """Message field 'header'."""
        return self._header

    @header.setter
    def header(self, value):
        if __debug__:
            from std_msgs.msg import Header
            assert \
                isinstance(value, Header), \
                "The 'header' field must be a sub message of type 'Header'"
        self._header = value

    @builtins.property
    def thrust(self):
        """Message field 'thrust'."""
        return self._thrust

    @thrust.setter
    def thrust(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'thrust' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'thrust' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._thrust = value

    @builtins.property
    def rlink_thrust(self):
        """Message field 'rlink_thrust'."""
        return self._rlink_thrust

    @rlink_thrust.setter
    def rlink_thrust(self, value):
        if __debug__:
            from geometry_msgs.msg import Vector3
            assert \
                isinstance(value, Vector3), \
                "The 'rlink_thrust' field must be a sub message of type 'Vector3'"
        self._rlink_thrust = value

    @builtins.property
    def moments(self):
        """Message field 'moments'."""
        return self._moments

    @moments.setter
    def moments(self, value):
        if __debug__:
            from geometry_msgs.msg import Vector3
            assert \
                isinstance(value, Vector3), \
                "The 'moments' field must be a sub message of type 'Vector3'"
        self._moments = value