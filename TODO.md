## TODO's
### TODO order
- README
- Markdown toolbar
- Prepare for first release


### Big TODO's
- Prepare for first release
  - Add support for compiling from .pro [Added in branch `static_build`]
  - Check minimal qt version (ex. 5.5, or 5.2)
  - Add qca as vendor subproject [Added in branch `static_build`]
  
- README
  - Write requirements and build instructions
  - Screenshots


### Current TODO's (before release)
- Custom groups of tabs

- Logging. Seriously, why it isn't there yet ? (Store as array of objs, with message, level, class[if it's possible]). 
  - Widget to view logs in app.
  - Add logging to already written code for debug/bug hunting.

- Options for compression, encryption(yes, return the old deleted system), backups and encryption of whole storage file
  - Like encryption of all docs, with password dialog on docs loading ? Or, instead use `encryption plugin` for all. That will leave metadata(name, last edit) unencrypted, but who cares ?

- Fix 2 bugs:
  - Windows blinks multiple times on start
  - Don't work correctly with dock until hidden to tray and shown back
  - Multiple (10-12) random saves after app starts (Maybe it's just auto save after edit ?)

- Tab Plugin for content encryption (Show dialog when tab opens)

### Low priority TODO's
- Write docs in code

- Restore and Diff for Backup

- View-only mode for LinkGroup

- Add markdown syntax highlighting and toolbar

- Double-Shift or some other shortcut to quickly go to any tab | switch options

- Themes [Light, Dark] as default, and custom (JSON)

- Encryption of storage with local password
  - Remember me, for time set by user


#### Other 
##### Needs further checking
- network/NCrypt:decrypt - Validation error prints only to console and message decryption isn't stopped


##### Maybe
- Rewrite to Model-View, to cleanup code and use ?less? code
- Move all "secure" variables from storage to separate file or leave there but encrypted like docs (for ex. to SSecure)
- Move login/register logic to SSecure
- Sync:
  - TOTP [repo 1](https://github.com/RavuAlHemio/cpptotp), [repo 2](https://github.com/andreagrandi/QGoogleAuth)