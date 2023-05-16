# vgui_controls.cmake

set(VGUI_CONTROLS_DIR ${CMAKE_CURRENT_LIST_DIR})
set(
	VGUI_CONTROLS_SOURCE_FILES

	"${VGUI_CONTROLS_DIR}/AnalogBar.cpp"
	"${VGUI_CONTROLS_DIR}/AnimatingImagePanel.cpp"
	"${VGUI_CONTROLS_DIR}/AnimationController.cpp"
	"${VGUI_CONTROLS_DIR}/BitmapImagePanel.cpp"
	"${VGUI_CONTROLS_DIR}/BuildFactoryHelper.cpp"
	"${VGUI_CONTROLS_DIR}/BuildGroup.cpp"
	"${VGUI_CONTROLS_DIR}/BuildModeDialog.cpp"
	"${VGUI_CONTROLS_DIR}/Button.cpp"
	"${VGUI_CONTROLS_DIR}/CheckButton.cpp"
	"${VGUI_CONTROLS_DIR}/CheckButtonList.cpp"
	"${VGUI_CONTROLS_DIR}/CircularProgressBar.cpp"
	"${VGUI_CONTROLS_DIR}/ComboBox.cpp"
	"${VGUI_CONTROLS_DIR}/consoledialog.cpp"
	"${VGUI_CONTROLS_DIR}/ControllerMap.cpp"
	"${VGUI_CONTROLS_DIR}/controls.cpp"
	"${VGUI_CONTROLS_DIR}/cvartogglecheckbutton.cpp"
	"${VGUI_CONTROLS_DIR}/DirectorySelectDialog.cpp"
	"${VGUI_CONTROLS_DIR}/Divider.cpp"
	"${VGUI_CONTROLS_DIR}/EditablePanel.cpp"
	"${VGUI_CONTROLS_DIR}/ExpandButton.cpp"
	"${VGUI_CONTROLS_DIR}/FileOpenDialog.cpp"
	"${VGUI_CONTROLS_DIR}/FileOpenStateMachine.cpp"
	"${SRCDIR}/public/filesystem_helpers.cpp"
	"${VGUI_CONTROLS_DIR}/FocusNavGroup.cpp"
	"${VGUI_CONTROLS_DIR}/Frame.cpp"
	"${VGUI_CONTROLS_DIR}/GraphPanel.cpp"
	"${VGUI_CONTROLS_DIR}/HTML.cpp"
	"${VGUI_CONTROLS_DIR}/Image.cpp"
	"${VGUI_CONTROLS_DIR}/ImageList.cpp"
	"${VGUI_CONTROLS_DIR}/ImagePanel.cpp"
	"${VGUI_CONTROLS_DIR}/InputDialog.cpp"
	"${VGUI_CONTROLS_DIR}/KeyBindingHelpDialog.cpp"
	"${VGUI_CONTROLS_DIR}/KeyBoardEditorDialog.cpp"
	"${VGUI_CONTROLS_DIR}/KeyRepeat.cpp"
	"${VGUI_CONTROLS_DIR}/Label.cpp"
	"${VGUI_CONTROLS_DIR}/ListPanel.cpp"
	"${VGUI_CONTROLS_DIR}/ListViewPanel.cpp"
	"${VGUI_CONTROLS_DIR}/Menu.cpp"
	"${VGUI_CONTROLS_DIR}/MenuBar.cpp"
	"${VGUI_CONTROLS_DIR}/MenuButton.cpp"
	"${VGUI_CONTROLS_DIR}/MenuItem.cpp"
	"${VGUI_CONTROLS_DIR}/MessageBox.cpp"
	"${VGUI_CONTROLS_DIR}/MessageDialog.cpp"
	"${VGUI_CONTROLS_DIR}/Panel.cpp"
	"${VGUI_CONTROLS_DIR}/PanelListPanel.cpp"
	"${VGUI_CONTROLS_DIR}/PerforceFileExplorer.cpp"
	"${VGUI_CONTROLS_DIR}/PerforceFileList.cpp"
	"${VGUI_CONTROLS_DIR}/perforcefilelistframe.cpp"
	"${VGUI_CONTROLS_DIR}/ProgressBar.cpp"
	"${VGUI_CONTROLS_DIR}/ProgressBox.cpp"
	"${VGUI_CONTROLS_DIR}/PropertyDialog.cpp"
	"${VGUI_CONTROLS_DIR}/PropertyPage.cpp"
	"${VGUI_CONTROLS_DIR}/PropertySheet.cpp"
	"${VGUI_CONTROLS_DIR}/QueryBox.cpp"
	"${VGUI_CONTROLS_DIR}/RadioButton.cpp"
	"${VGUI_CONTROLS_DIR}/RichText.cpp"
	"${VGUI_CONTROLS_DIR}/RotatingProgressBar.cpp"
	"${VGUI_CONTROLS_DIR}/savedocumentquery.cpp"
	"${VGUI_CONTROLS_DIR}/ScalableImagePanel.cpp"
	"${VGUI_CONTROLS_DIR}/ScrollableEditablePanel.cpp"
	"${VGUI_CONTROLS_DIR}/ScrollBar.cpp"
	"${VGUI_CONTROLS_DIR}/ScrollBarSlider.cpp"
	"${VGUI_CONTROLS_DIR}/SectionedListPanel.cpp"
	"${VGUI_CONTROLS_DIR}/Slider.cpp"
	"${VGUI_CONTROLS_DIR}/Splitter.cpp"
	"${VGUI_CONTROLS_DIR}/subrectimage.cpp"
	"${VGUI_CONTROLS_DIR}/TextEntry.cpp"
	"${VGUI_CONTROLS_DIR}/TextImage.cpp"
	"${VGUI_CONTROLS_DIR}/ToggleButton.cpp"
	"${VGUI_CONTROLS_DIR}/Tooltip.cpp"
	"${VGUI_CONTROLS_DIR}/ToolWindow.cpp"
	"${VGUI_CONTROLS_DIR}/TreeView.cpp"
	"${VGUI_CONTROLS_DIR}/TreeViewListControl.cpp"
	"${VGUI_CONTROLS_DIR}/URLLabel.cpp"
	"${VGUI_CONTROLS_DIR}/WizardPanel.cpp"
	"${VGUI_CONTROLS_DIR}/WizardSubPanel.cpp"
	"${SRCDIR}/vgui2/src/vgui_key_translation.cpp"

	"${SRCDIR}/public/vgui_controls/AnalogBar.h"
	"${SRCDIR}/public/vgui_controls/AnimatingImagePanel.h"
	"${SRCDIR}/public/vgui_controls/AnimationController.h"
	"${SRCDIR}/public/vgui_controls/BitmapImagePanel.h"
	"${SRCDIR}/public/vgui_controls/BuildGroup.h"
	"${SRCDIR}/public/vgui_controls/BuildModeDialog.h"
	"${SRCDIR}/public/vgui_controls/Button.h"
	"${SRCDIR}/public/vgui_controls/CheckButton.h"
	"${SRCDIR}/public/vgui_controls/CheckButtonList.h"
	"${SRCDIR}/public/vgui_controls/CircularProgressBar.h"
	"${SRCDIR}/public/Color.h"
	"${SRCDIR}/public/vgui_controls/ComboBox.h"
	"${SRCDIR}/public/vgui_controls/consoledialog.h"
	"${SRCDIR}/public/vgui_controls/ControllerMap.h"
	"${SRCDIR}/public/vgui_controls/Controls.h"
	"${SRCDIR}/public/vgui_controls/cvartogglecheckbutton.h"
	"${SRCDIR}/public/vgui_controls/DialogManager.h"
	"${SRCDIR}/public/vgui_controls/DirectorySelectDialog.h"
	"${SRCDIR}/public/vgui_controls/Divider.h"
	"${SRCDIR}/public/vgui_controls/EditablePanel.h"
	"${SRCDIR}/public/vgui_controls/ExpandButton.h"
	"${SRCDIR}/public/vgui_controls/FileOpenDialog.h"
	"${SRCDIR}/public/vgui_controls/FileOpenStateMachine.h"
	"${SRCDIR}/public/filesystem.h"
	"${SRCDIR}/public/filesystem_helpers.h"
	"${SRCDIR}/public/vgui_controls/FocusNavGroup.h"
	"${SRCDIR}/public/vgui_controls/Frame.h"
	"${SRCDIR}/public/vgui_controls/GraphPanel.h"
	"${SRCDIR}/public/vgui_controls/HTML.h"
	"${SRCDIR}/public/vgui_controls/Image.h"
	"${SRCDIR}/public/vgui_controls/ImageList.h"
	"${SRCDIR}/public/vgui_controls/ImagePanel.h"
	"${SRCDIR}/public/vgui_controls/InputDialog.h"
	"${SRCDIR}/public/tier1/interface.h"
	"${SRCDIR}/public/vgui_controls/KeyBindingHelpDialog.h"
	"${SRCDIR}/public/vgui_controls/KeyBindingMap.h"
	"${SRCDIR}/public/vgui_controls/KeyBoardEditorDialog.h"
	"${SRCDIR}/public/vgui_controls/KeyRepeat.h"
	"${SRCDIR}/public/tier1/KeyValues.h"
	"${SRCDIR}/public/vgui_controls/Label.h"
	"${SRCDIR}/public/vgui_controls/ListPanel.h"
	"${SRCDIR}/public/vgui_controls/ListViewPanel.h"
	"${SRCDIR}/public/tier0/memdbgoff.h"
	"${SRCDIR}/public/tier0/memdbgon.h"
	"${SRCDIR}/public/tier1/mempool.h"
	"${SRCDIR}/public/vgui_controls/Menu.h"
	"${SRCDIR}/public/vgui_controls/MenuBar.h"
	"${SRCDIR}/public/vgui_controls/MenuButton.h"
	"${SRCDIR}/public/vgui_controls/MenuItem.h"
	"${SRCDIR}/public/vgui_controls/MessageBox.h"
	"${SRCDIR}/public/vgui_controls/MessageDialog.h"
	"${SRCDIR}/public/vgui_controls/MessageMap.h"
	"${SRCDIR}/public/vgui_controls/Panel.h"
	"${SRCDIR}/public/vgui_controls/PanelAnimationVar.h"
	"${SRCDIR}/public/vgui_controls/PanelListPanel.h"
	"${SRCDIR}/public/vgui_controls/PerforceFileExplorer.h"
	"${SRCDIR}/public/vgui_controls/PerforceFileList.h"
	"${SRCDIR}/public/vgui_controls/perforcefilelistframe.h"
	"${SRCDIR}/public/vgui_controls/PHandle.h"
	"${SRCDIR}/public/vgui_controls/ProgressBar.h"
	"${SRCDIR}/public/vgui_controls/ProgressBox.h"
	"${SRCDIR}/public/vgui_controls/PropertyDialog.h"
	"${SRCDIR}/public/vgui_controls/PropertyPage.h"
	"${SRCDIR}/public/vgui_controls/PropertySheet.h"
	"${SRCDIR}/public/vgui_controls/QueryBox.h"
	"${SRCDIR}/public/vgui_controls/RadioButton.h"
	"${SRCDIR}/public/vgui_controls/RichText.h"
	"${SRCDIR}/public/vgui_controls/RotatingProgressBar.h"
	"${SRCDIR}/public/vgui_controls/savedocumentquery.h"
	"${SRCDIR}/public/vgui_controls/ScalableImagePanel.h"
	"${SRCDIR}/public/vgui_controls/ScrollableEditablePanel.h"
	"${SRCDIR}/public/vgui_controls/ScrollBar.h"
	"${SRCDIR}/public/vgui_controls/ScrollBarSlider.h"
	"${SRCDIR}/public/vgui_controls/SectionedListPanel.h"
	"${SRCDIR}/public/vgui_controls/Slider.h"
	"${SRCDIR}/public/vgui_controls/Splitter.h"
	"${SRCDIR}/public/vgui_controls/subrectimage.h"
	"${SRCDIR}/public/vgui_controls/TextEntry.h"
	"${SRCDIR}/public/vgui_controls/TextImage.h"
	"${SRCDIR}/public/vgui_controls/ToggleButton.h"
	"${SRCDIR}/public/vgui_controls/Tooltip.h"
	"${SRCDIR}/public/vgui_controls/ToolWindow.h"
	"${SRCDIR}/public/vgui_controls/TreeView.h"
	"${SRCDIR}/public/vgui_controls/TreeViewListControl.h"
	"${SRCDIR}/public/vgui_controls/URLLabel.h"
	"${SRCDIR}/public/tier1/utlmemory.h"
	"${SRCDIR}/public/tier1/utlrbtree.h"
	"${SRCDIR}/public/tier1/utlvector.h"
	"${SRCDIR}/public/vgui_controls/WizardPanel.h"
	"${SRCDIR}/public/vgui_controls/WizardSubPanel.h"
)

add_library(vgui_controls STATIC ${VGUI_CONTROLS_SOURCE_FILES})

set_property(TARGET vgui_controls PROPERTY FOLDER "Libs")

target_include_directories(
	vgui_controls PRIVATE
	"${SRCDIR}/thirdparty"
	"${SRCDIR}/thirdparty/cef"
)