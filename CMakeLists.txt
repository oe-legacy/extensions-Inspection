
# Create the extension library
ADD_LIBRARY(Extensions_Inspection
  Utils/TransformationNodeInspector.h
  Utils/TransformationNodeInspector.cpp
  Utils/RenderStateNodeInspector.h
  Utils/RenderStateNodeInspector.cpp
  Utils/LightInspector.h
  Utils/LightInspector.cpp
  Utils/CameraInspector.h
  Utils/CameraInspector.cpp
  Utils/PerspectiveViewingVolumeInspector.h
  Utils/PerspectiveViewingVolumeInspector.cpp
)
